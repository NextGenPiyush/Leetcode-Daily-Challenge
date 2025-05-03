#include<bits/stdc++.h>
using namespace std;

// problem Link: https://leetcode.com/problems/push-dominoes/description/
string pushDominoes(string dominoes); // Leetcode-838
string func(int j, int k, string &dominoes);

int main(){

    
    
    return 0;
}

string pushDominoes(string dominoes){
    int n = dominoes.size();

    string ans = "";
    int j = -1;
    int k = -1;
    bool flag = false;

    for(int i=0; i<n; i++){  // Time Complexity: O(n)
        if(dominoes[i] == '.') continue;
        k = i;
        if(j != -1) ans += dominoes[j];
        ans += func(j, k, dominoes);
        j = k;
        flag = true; 
    }

    if(flag == false){
        for(int i=0; i<n; i++) ans += '.';
        return ans;
    }

    for(int i=n-1; i>=0; i--){
        if(dominoes[i] == '.') continue;
        if(dominoes[i] == 'R') for(int j=i; j<n; j++) ans += 'R';
        else{
            ans += 'L';
            for(int j=i+1; j<n; j++) ans += '.';
        }
        break;
    }

    return ans;
}

string func(int j, int k, string &dominoes){
    string ans = "";

    if(j == -1){
        if(dominoes[k] == 'L') for(int i=j+1; i<k; i++) ans += 'L';
        else if(dominoes[k] == 'R') for(int i=j+1; i<k; i++) ans += '.';
    }
    else if(dominoes[j] == 'L' && dominoes[k] == 'L'){
        for(int i=j+1; i<k; i++) ans += 'L';
    }

    else if(dominoes[j] == 'R' && dominoes[k] == 'R'){
        for(int i=j+1; i<k; i++) ans += 'R';
    } 

    else if(dominoes[j] == 'L' && dominoes[k] == 'R'){
        for(int i=j+1; i<k; i++) ans += '.';
    }

    else if(dominoes[j] == 'R' && dominoes[k] == 'L'){
        if((j+k) % 2 == 0){
            for(int i=j+1; i<k; i++){
                if(i < (j+k)/2) ans += 'R';
                else if(i > (j+k)/2) ans += 'L';
                else ans += '.';
            }
        } 
        else{
            for(int i=j+1; i<k; i++){
                if(i <= (j+k)/2) ans += 'R';
                else if(i > (j+k)/2) ans += 'L';
            }
        }
    }

    return ans;
}

//***************************************** Alternate approach  *****************************************//

string pushDominoes(string dominoes){
    int n = dominoes.size();
    vector<int> forces(n, 0);
    
    int force = 0;
    for(int i = 0; i < n; ++i){
        if(dominoes[i] == 'R') force = n;
        else if(dominoes[i] == '.') force = max(force - 1, 0); 
        else force = 0;
        forces[i] += force;
    }

    force = 0;
    for(int i = n - 1; i >= 0; --i){
        if(dominoes[i] == 'L') force = n;
        else if(dominoes[i] == '.') force = max(force - 1, 0);
        else force = 0;
        forces[i] -= force;
    }
    
    string output;
    for(int netForce : forces){
        if(netForce > 0) output += 'R'; 
        else if(netForce < 0) output += 'L'; 
        else output += '.';
    }
    
    return output;
}

//***************************************** Alternate approach  *****************************************//

string pushDominoes(string dominoes) {
    int n = dominoes.length();
    
    vector<int> rightClosestL(n);  // Time complexity: O(n)
    vector<int> leftClosestR(n);   // Space complexity: O(n)
    
    //Moving right to left to find rightClosestL
    for(int i = n-1; i >= 0; i--) {
        if(dominoes[i] == 'L') rightClosestL[i] = i; //L starts from me
        else if(dominoes[i] == '.') rightClosestL[i] = i < n-1 ? rightClosestL[i+1] : -1;
        else rightClosestL[i] = -1;
    }
    
    //Moving left to right to find leftClosestR
    for(int i = 0; i < n; i++) {
        if(dominoes[i] == 'R') leftClosestR[i] = i; //R starts from me
        else if(dominoes[i] == '.') leftClosestR[i] = i > 0 ? leftClosestR[i-1] : -1;
        else leftClosestR[i] = -1;
    }
    
    string result(n, ' ');
    
    for(int i = 0; i < n; i++) {
        int distRightL = abs(i-rightClosestL[i]); //distance from 'R' towards my left direction
        int distLeftR  = abs(i-leftClosestR[i]);  //distance from 'L' towards my right direction
        
        if(rightClosestL[i] == leftClosestR[i]) result[i] = '.';
        else if(rightClosestL[i] == -1) result[i] = 'R';  //No force from right direction towards left, so move R
        else if(leftClosestR[i] == -1) result[i] = 'L'; //No force from left direction towards right, so move L
        else if(distLeftR == distRightL) result[i] = '.'; //Equal force from left and right
        else result[i] = distRightL < distLeftR ? 'L': 'R'; //which ever force is greater
    }
    
    return result;
}
