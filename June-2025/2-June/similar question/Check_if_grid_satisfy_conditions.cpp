#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/check-if-grid-satisfies-conditions/description/

bool satisfiesConditions(vector<vector<int>>& grid); // Leetcode-3142

int main(){



    return 0;
}

bool satisfiesConditions(vector<vector<int>>& grid){
    int rows = grid.size();
    int columns = grid[0].size();  // time complexity: O(mn) 

    if(columns == 1) for(int i=1; i<rows; i++) if(grid[i][0] != grid[i-1][0]) return false;
    for(int j=0; j<columns-1; j++) if(grid[0][j] == grid[0][j+1]) return false;  // O(n)

    for(int j=0; j<columns; j++){  // O(mn)
        for(int i=1; i<rows; i++){
            if(grid[i-1][j] != grid[i][j]) return false; 
        }
    }

    return true;
}