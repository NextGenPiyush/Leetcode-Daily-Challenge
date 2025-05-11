#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/fill-a-special-grid/description/
vector<vector<int>> specialGrid(int n); // Leetcode-3537

int main(){
    
    
    
    return 0;
}

vector<vector<int>> specialGrid(int n){
    n = pow(2,n);

    vector<vector<int>> ans(n, vector<int>(n,0));
    int num = 0;
    int start_row = 0, end_row = n-1, start_col = 0, end_col = n-1;
    func(start_row, end_row, start_col, end_col, num, ans);

    return ans;
}

void func(int start_row, int end_row, int start_col, int end_col, int &num, vector<vector<int>> &ans){
    if(start_row == end_row && start_col == end_col){
        ans[start_row][start_col] = num++;
        return;
    }

    int mid_row = (start_row + end_row) / 2;
    int mid_col = (start_col + end_col) / 2;

    func(start_row, mid_row, mid_col + 1, end_col, num, ans);  // Top-right
    func(mid_row + 1, end_row, mid_col + 1, end_col, num, ans); // Bottom-right
    func(mid_row + 1, end_row, start_col, mid_col, num, ans);  // Bottom-left
    func(start_row, mid_row, start_col, mid_col, num, ans);  // top-left
}