#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/?envType=daily-question&envId=2025-05-10
long long minSum(vector<int>& nums1, vector<int>& nums2);  // Leetcode-2918

int main(){
    
    
    
    return 0;
}

long long minSum(vector<int>& nums1, vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();  // Total time complexity: O(n) + O(m)

    long long sum1 = 0;
    int zero_in_1 = 0;
    for(int i=0; i<n; i++){  
        sum1 += (nums1[i] == 0) ? 1 : nums1[i];
        zero_in_1 += (nums1[i] == 0) ? 1 : 0;
    }

    long long sum2 = 0;
    int zero_in_2 = 0;
    for(int i=0; i<m; i++){
        sum2 += (nums2[i] == 0) ? 1 : nums2[i];
        zero_in_2 += (nums2[i] == 0) ? 1 : 0;
    }

    if((sum1 < sum2 && zero_in_1 == 0) || (sum2 < sum1 && zero_in_2 == 0)) return -1;
    return max(sum1, sum2);
}