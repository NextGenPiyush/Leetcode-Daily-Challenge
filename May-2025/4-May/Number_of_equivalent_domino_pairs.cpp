#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=daily-question&envId=2025-05-04
int numEquivDominoPairs(vector<vector<int>>& dominoes); // Leetcode-1128

int main(){

    
    
    return 0;
}

int numEquivDominoPairs(vector<vector<int>>& dominoes){
    map<pair<int, int>, int> mp;

    for(auto &d : dominoes){  // Time complexity: O(n*logn)
        if(d[0] > d[1]) swap(d[0], d[1]);
        mp[{d[0],d[1]}]++;    // O(logn)
    }

    int result = 0;
    for(auto &it : mp){
        int freq = it.second;
        result += freq * (freq-1)/2; 
    }

    return result;
}

//***************************************** Alternate Approach *****************************************//

int numEquivDominoPairs(vector<vector<int>>& dominoes){
    vector<int> vec(100); // as donimoes value can be atmost 9 and our hash value can be max (9*10 + 9 = 99)

    int result = 0;
    for(auto &d : dominoes){  // Time complexity: O(n)
        if(d[0] > d[1]) swap(d[0], d[1]);  // Space complexity: O(96) ~ O(1) --> constant

        int num = d[0]*10 + d[1]; //(a, b) --> a*10 + b;
        result += vec[num];
        vec[num]++;
    }

    return result;
}