#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13

int minimizeMax(vector<int>& nums, int p); // Leeetcode-2616
bool isValid(vector<int>& nums, int mid, int p);

int main(){
    

    
    return 0;
}

int minimizeMax(vector<int>& nums, int p){
    int n = nums.size();
    sort(begin(nums), end(nums));  // O(nlogn)

    // Time complexity: O(n*log(n)) and space complexity: O(1)
        
    int low = 0;
    int high = nums[n-1] - nums[0];  // max difference possible
    int result = INT_MAX;

    while(low <= high){  // O(log(max_diff)*n)
        int mid = low + (high-low)/2;
        if(isValid(nums, mid, p)){  // if we get our ans search pairs for further lesser difference
            result = mid;
            high = mid-1;  
        } 
        else low = mid+1;  // if we did't get our ans search pairs for further greater difference 
    }

    return result;
}

bool isValid(vector<int>& nums, int mid, int p){
    int n = nums.size();
    int i = 0;
    int pairs = 0;

    while(i < n-1){  // O(n)
        if(nums[i+1] - nums[i] <= mid){
            pairs++;
            i += 2;  // if we got the pair move to next to next element
        } 
        else i++; // if we dont get the pair move to the next element
    }
    return pairs >= p;  // if we get the required no of pairs then return true else false 
}