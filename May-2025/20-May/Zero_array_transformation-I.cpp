#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/zero-array-transformation-i/?envType=daily-question&envId=2025-05-20
bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries); // Leetcode-3355

int main(){

    // Brute force: go to each query and decrement elements of num by traversing on the nums vector
    // time complexity: O(m*n) and space complexity: O(1)
    // where n --> nums.size() and m --> queries.size()

    return 0;
}

bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries){
    int n = nums.size();
    int m = queries.size();    // Time complexity: O(n+m)
    vector<int> v(n,0);       // space complexity: O(n)

    for(int i = 0; i < m; i++){  // O(m) for making a vector which decrement the nums
        v[queries[i][0]]--;
        if(queries[i][1] + 1 < n) v[queries[i][1] + 1]++; 
    }
    // we can also do that v[queries[i][0]]++ and v[queries[i][1] + 1]-- which will help us to reduce the computation of addition, simple we will check if nums[i] > v[i] then return false

    if(nums[0] + v[0] > 0) return false;  // checking whether v can decrement elements of num to 0  
    for(int i = 1; i < n; i++){  // O(n)
        v[i] += v[i-1];
        if(nums[i] + v[i] > 0) return false;  
        // if nums[i] become zero after decrement then dont decrement it further 
    }

    return true;
}