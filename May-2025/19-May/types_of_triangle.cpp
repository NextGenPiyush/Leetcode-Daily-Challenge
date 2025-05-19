#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/type-of-triangle/description/?envType=daily-question&envId=2025-05-19
string triangleType(vector<int>& nums); // Leetcode-3024

int main(){



    return 0;
}

string triangleType(vector<int>& nums){
    int a = nums[0], b = nums[1], c = nums[2];  // Time complexity: O(1)

    if(a == b && b == c) return "equilateral";
    if(a + b > c && a + c > b && b + c > a){
        if(a == b || b == c || a == c) return "isosceles";
        return "scalene";
    }

    return "none";
}

//******************************************* Alternate Method *******************************************//

string triangleType(vector<int>& nums){
    sort(nums.begin(), nums.end());  // Time complexity: O(1)

    if (nums[0] + nums[1] <= nums[2]) return "none";  // checking condition with the smallest two lengths
    else if(nums[0] == nums[2]) return "equilateral";  // first and last  equal then middle one will also equal
    else if (nums[0] == nums[1] || nums[1] == nums[2]) return "isosceles";  // any two length are equal
    else return "scalene";  // no length is equal
}