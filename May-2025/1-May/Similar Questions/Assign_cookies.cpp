#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/assign-cookies/
int findContentChildren(vector<int>& g, vector<int>& s); // Leetcode-455

int main(){
    
    
    
    return 0;
}

int findContentChildren(vector<int>& greed, vector<int>& size){
    int n = greed.size();
    int m = size.size();   // Time complexity: O(n*logn) + O(max(n,m))
 
    sort(greed.begin(), greed.end());  // O(n*logn)
    sort(size.begin(), size.end()); // O(n*logn)

    int i = 0, j = 0;
    while(i < n && j < m){  // O(max(n,m))
        if(greed[i] <= size[j]) i++;  // ith child assigned jth cookies
        j++; 
    } 

    return i;
}