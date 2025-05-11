#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/equal-sum-grid-partition-i/description/
bool canPartitionGrid(vector<vector<int>>& grid); // Leetcode-3546

int main(){

    

    return 0;
}

bool canPartitionGrid(vector<vector<int>>& grid){
    int row = grid.size();
    int col = grid[0].size();    // Total time complexity: O(n*m) + O(n)

    vector<long> row_computation(row, 0);  
    for(int i = 0; i < row; i++){  // O(n*m)
        long sum = 0;
        for(int j = 0; j < col; j++) sum += grid[i][j];
        row_computation[i] = sum;
    }
    if(check(row_computation)) return true;  // O(n)

    vector<long> col_computation(col, 0);
    for(int j = 0; j < col; j++){     // O(n*m)
        long sum = 0;
        for(int i = 0; i < row; i++) sum += grid[i][j];
        col_computation[j] = sum;
    }
    if(check(col_computation)) return true;  // O(n)

    return false;
}

bool check(vector<long> &arr){  
    int n = arr.size();
    if(n == 1) return false;

    vector<long> prefix(n, 0);  // O(n)
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) prefix[i] += prefix[i-1] + arr[i];

    vector<long> sufix(n, 0);  // O(n)
    sufix[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) sufix[i] += sufix[i+1] + arr[i];

    for(int i = 0; i < n-1; i++) if(prefix[i] == sufix[i+1]) return true;  // O(n)
    return false;
}