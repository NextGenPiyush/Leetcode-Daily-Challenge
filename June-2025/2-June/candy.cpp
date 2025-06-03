#include<bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings); // Leetcode-135

int main(){

    
    
    
    
    return 0;
}

int candy(vector<int>& ratings){   // this code is giving wrong ans
    int n = ratings.size();
    if(n == 1) return 1;
    
    int increasing = 0, decreasing = 0;
    int ans = 0;

    if(n == 2 && ratings[0] == ratings[1]) return 2;
    else if(n == 2 && ratings[0] != ratings[1]) return 3;
    
    if(ratings[1] < ratings[0]) decreasing++;
    ans++;

    for(int i=1; i<n; i++){
        if(ratings[i] < ratings[i-1]){
            decreasing++;
            ans += decreasing;
            increasing = 0;
        }
        else if(ratings[i] > ratings[i-1]){
            increasing++;
            ans += increasing+1;
            decreasing = 0;
        }
        else if(ratings[i] == ratings[i-1]){
            increasing = 0;
            decreasing = 0;
            if((i != n-1 && ratings[i+1] > ratings[i]) || i == n-1) ans++;
            else if(i != n-1 && ratings[i+1] < ratings[i]) ans += 2;
        }
    }
        
    return ans;
}