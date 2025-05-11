#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/submissions/1631088572/
int maxFreqSum(string s); // Leetcode-3541

int main(){
    
    
    
    return 0;
}

int maxFreqSum(string s){
    vector<int> freq(27, 0);  // Total Time complexity: O(2n)
    for(auto ch : s) freq[ch-'a']++;  // O(n) where n --> length of string

    int vowel = 0, consonant = 0;  
    for(auto ch : s){  // O(n)
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowel = max(vowel, freq[ch-'a']);
        else consonant = max(consonant, freq[ch-'a']);
    }

    return vowel + consonant;
}