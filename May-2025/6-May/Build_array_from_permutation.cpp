#include<bits/stdc++.h>
using namespace std;

vector<int> buildArray(vector<int>& nums); // Leetcode-1290

int main(){

    

    return 0;
}

vector<int> buildArray(vector<int>& nums){
    int n = nums.size();
    
    // vector<int> ans(n);  // Space complexity: o(n)
    // for(int i = 0; i < n; i++) ans[i] = nums[nums[i]];  // Time complexity: o(n)
    // return ans;

    for(int i = 0; i < n; i++){   // time complexity: O(n)
        int original_value = nums[i];   // space complexity: O(1)
        int new_value = nums[nums[i]];
        nums[i] = (new_value % n) * n + original_value;
    }

    for(int i = 0; i < n; i++) nums[i] = nums[i] % n;

    return nums;

}