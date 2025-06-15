#include<bits/stdc++.h>
using namespace std;

// Problem Lin: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

int minDifference(vector<int>& nums); // Leetcode-1509

int main(){
    
    
    
    return 0;
}

int minDifference(vector<int>& nums){
    int n = nums.size();
    if(n <= 4) return 0;
    sort(nums.begin(), nums.end());  // Time commplexity: O(n*log(n)) and space complexity: O(1)

    // time complexity: O(n) better than sorting the whole vector as we need only first and last 4 elements of the vector in the sorted order and space complexity: O(1)
    
    // Partially sort the first four elements
    partial_sort(begin(nums), begin(nums) + 4, end(nums));  // O(n*log(4)) ~ O(n)
    // Find the 4th largest element
    nth_element(begin(nums) + 4, begin(nums) + (n - 4), end(nums)); // O(n)
    // Sort the last four elements
    sort(begin(nums) + (n - 4), end(nums));  // O(4*log(4)) ~ O(1)
    
    int min_diff = INT_MAX; 
    // Four scenarios to compute the minimum difference
    for(int i = 0; i < 4; i++) min_diff = min(min_diff, nums[n-(4-i)] - nums[i]);
    // min_diff = min(min_diff, nums[n-4] - nums[0]);
    // min_diff = min(min_diff, nums[n-1] - nums[3]);
    // min_diff = min(min_diff, nums[n-3] - nums[1]);
    // min_diff = min(min_diff, nums[n-2] - nums[2]);

    return min_diff;
}

// Partial_sort(v.begin(), v.begin()+k, v.end()); --> sort first k elements in the vector 
// time complexity of partial sorting: O(n*log(k)) 

// nth_element(v.begin(), v.begin()+k, v.end()); --> place the kth element at the actuall position into as placed after sorting the vector, and segrgate all the smaller and greater element in the vector as compared to the kth-element
