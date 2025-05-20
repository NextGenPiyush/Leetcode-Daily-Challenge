#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/range-addition/description/
vector<int> getModifiedArray(int length, vector<vector<int>>& updates);  // Leetcode-370 Locked

int main(){
    
    // Brute force: go to every query and update vector by traversing every time
    // Time complexity: O(m*n) where m --> updates.size() and n --> lenght
    
    return 0;
}

vector<int> getModifiedArray(int length, vector<vector<int>>& updates){
    vector<int> diff(length, 0);  // Time complexity: O(m + length) and space complexity: O(length)
    
    for(const auto& update : updates){  // Step 1: Apply updates using the difference array O(m)
        diff[update[0]] += update[2];   // Add increment at startIndex
        if(update[1] + 1 < length) diff[update[1] + 1] -= update[2]; // Subtract increment after endIndex
    }

    // Step 2: Compute the final array from the difference array
    for(int i = 1; i < length; ++i) diff[i] += diff[i-1]; // O(n)
    return diff;
}