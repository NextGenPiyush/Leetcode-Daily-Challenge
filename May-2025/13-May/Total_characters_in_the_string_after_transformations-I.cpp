#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/?envType=daily-question&envId=2025-05-13

int MOD = 1e9 + 7;
int lengthAfterTransformations(string s, int t); // Leetcode-3335

int main(){

    
    
    return 0;
}

int lengthAfterTransformations(string s, int t){
    vector<long> freq(26,0);                           // Total Time complexity: O(n) + O(t)
    for(auto ch : s) freq[ch-'a']++;                   // space complexity: O(1) --> for storing freq

    while(t--){
        long temp = freq[25];  // storing how much z are present in the string
        freq[25] = 0;  // now we have to set freq(z) --> 0

        for(int i = 24; i >= 0; i--){
            freq[i+1] = freq[i];
            freq[i] = 0;
        }

        freq[0] = freq[0]%MOD + temp%MOD; // adding frequency of z into a and b as z --> ab
        freq[1] = freq[1]%MOD + temp%MOD;
    }

    long ans;
    for(int i = 0; i < 26; i++) ans += freq[i]; // counting all the frequency to get length of the string
    return ans%MOD;
}