#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/
int minDeletion(string s, int k); // Leetcode-3545

int main(){  

    

    return 0;
}

int minDeletion(string s, int k){
    vector<int> freq(27,0);
    for(auto ch : s) freq[ch-'a']++;

    sort(freq.begin(), freq.end(), greater<int>());
        
    int ans = 0;
    for(int i=k; i<27; i++) ans += freq[i];
    return ans;
}