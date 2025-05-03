#include<bits/stdc++.h>
using namespace std;

int minDominoRotations(vector<int>& tops, vector<int>& bottoms); // Leetcode-1007
int check(int x, vector<int>& A, vector<int>& B);

int main(){

    
    
    return 0;
}

int minDominoRotations(vector<int>& tops, vector<int>& bottoms){
    int n = tops.size();
    int ans = INT_MAX;

    bool checking_top = true;
    int swap = 0;               // Time Complexity: O(n)
    int extra_swap = 0;

    int a = tops[0];
    for(int i = 1; i < n; i++){
        if(tops[i] == a && bottoms[i] == a) extra_swap++; // these are the extra swaps we we are taking twice
        if(tops[i] == a) continue; // already present at top, no need to make swap
        else if(bottoms[i] == a) swap++;
        else{
            checking_top = false;
            break;
        }
    }

    // swap --> swaps required to make top elements == a
    // n-swaps --> swaps requied to make bottom element == a 
    //  extra_swap --> when both top[i] == bottom[i] == a
    if(checking_top) ans = min({ans, swap, n - swap - extra_swap});

    bool checking_bottoms = true;
    swap = 0;        // setting swaps 0 for performing operations
    extra_swap = 0;  // setting extra_swaps 0 for performing operations
    a = bottoms[0];

    for(int i = 1; i < n; i++){
        if(tops[i] == a && bottoms[i] == a) extra_swap++;
        if(bottoms[i] == a) continue;
        else if(tops[i] == a) swap++;
        else{
            checking_bottoms = false;
            break;
        }
    }
    if(checking_bottoms) ans = min({ans, swap, n - swap - extra_swap});

    if(checking_bottoms == false && checking_top == false) return -1;  // not possible
    else return ans;
}


//****************************************** Alternate Approach ******************************************//

int check(int x, vector<int>& A, vector<int>& B){
    int rotations_a = 0, rotations_b = 0;
    int n = A.size();

    for(int i = 0; i < n; ++i){
        if(A[i] != x && B[i] != x) return -1;
        else if(A[i] != x) rotations_a++;
        else if(B[i] != x) rotations_b++;
    }

    return min(rotations_a, rotations_b);
}

int minDominoRotations(vector<int>& tops, vector<int>& bottoms){
    int rotations = check(tops[0], tops, bottoms);

    if(rotations != -1 || tops[0] == bottoms[0]) return rotations;
    else return check(bottoms[0], tops, bottoms);
}
