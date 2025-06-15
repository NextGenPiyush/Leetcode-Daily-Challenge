#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/minimum-absolute-difference/

vector<vector<int>> minimumAbsDifference(vector<int>& arr); // Leetcode-1200

int main(){

    
    
    return 0;
}

vector<vector<int>> minimumAbsDifference(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> ans; // Time complexity: O(n*log(n) + n) and space complexity: O(1) --> no extra space

    sort(arr.begin(), arr.end());  // O(n*log(n))
    ans.push_back({arr[0], arr[1]});
    int diff = arr[1] - arr[0]; 

    for(int i = 1; i < n-1; i++){  // O(n)
        if(arr[i+1] - arr[i] == diff) ans.push_back({arr[i], arr[i+1]}); 
        else if(arr[i+1] - arr[i] < diff){  // we got the lesser diff, clear the vector and fill the new pair
            diff = arr[i+1] - arr[i];
            ans.clear();
            ans.push_back({arr[i], arr[i+1]});
        }
    }

    return ans;
}