#include<bits/stdc++.h>
using namespace std;

// ProblemLink: https://leetcode.com/problems/three-consecutive-odds/?envType=daily-question&envId=2025-05-11
bool threeConsecutiveOdds(vector<int>& arr); // Leetcode-1550

int main(){

    

    return 0;
}

bool threeConsecutiveOdds(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<=n-3; i++) if(arr[i]%2 && arr[i+1]%2 && arr[i+2]%2) return true;
    return false;
}