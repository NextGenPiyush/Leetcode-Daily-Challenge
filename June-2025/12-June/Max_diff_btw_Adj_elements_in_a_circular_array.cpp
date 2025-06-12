#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/?envType=daily-question&envId=2025-06-12

int maxAdjacentDistance(vector<int>& nums);  // Leetcode-3423

int main(){



    return 0;
}

int maxAdjacentDistance(vector<int>& nums){
    int n = nums.size();
    int max_abb_diff = INT_MIN;  // Time complexity: O(n) and space complexity: O(1)

    for(int i=0; i<n-1; i++) max_abb_diff = max(max_abb_diff, abs(nums[i] - nums[i+1]));
    max_abb_diff = max(max_abb_diff, abs(nums[0] - nums[n-1]));  // circular array 

    return max_abb_diff;
}