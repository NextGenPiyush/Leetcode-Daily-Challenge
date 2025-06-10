#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/editorial/?envType=daily-question&envId=2025-06-10

int maxDifference(string s); // Leetcode-3442

int main(){
    
    
    
    return 0;
}

int maxDifference(string s){
    vector<int> freq(26,0);  // space complexity: O(1)
    for(auto ch : s) freq[ch-'a']++;  // time complexity: O(n)

    int max_odd_freq = 0;
    int min_even_freq = INT_MAX;

    for(int i=0; i<26; i++){  // O(1)
        if(freq[i] % 2 == 0 && freq[i] != 0) min_even_freq = min(min_even_freq, freq[i]);
        else max_odd_freq = max(max_odd_freq, freq[i]);
    }

    if(min_even_freq == INT_MIN) return max_odd_freq;
    return (max_odd_freq - min_even_freq);
}