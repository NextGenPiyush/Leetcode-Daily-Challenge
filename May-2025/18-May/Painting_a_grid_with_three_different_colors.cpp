#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/?envType=daily-question&envId=2025-05-18

int mod = 1e9 + 7;

vector<vector<int>> dp;  // Approach-1 
int colorTheGrid(int m, int n); // Leetcode-1931
void generateColumnState(string curr, char prevChar, int length, int rows, vector<string> &columnStates);
int func(int remColumn, int prevIdx, vector<string> &columnStates);
bool check(string prevState, string currState);


vector<vector<int>> dp;  // Approach-2 Using bit-masking
int colorTheGrid(int m, int n); // Leetcode-1931
int solve(int &rows,int &cols,int currRow, int currCol ,int curr_state, int prev_state);

int main(){
    
    // Similar Question Leetcode-1411
    // Problem Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
    
    return 0;
}

void generateColumnState(string curr, char prevChar, int length, int rows, vector<string> &columnStates){
    if(length == rows){
        columnStates.push_back(curr);  //  this function helps us to Generating all states of a column
        return;
    }

    for(char ch : {'R', 'G', 'B'}){  // O(3)
        if(ch == prevChar) continue;  // but this will run for 2 times only one iteration will be reduced due to this line so time complexity: O(2)
        generateColumnState(curr+ch, ch, length+1, rows, columnStates);
    }
}

int colorTheGrid(int m, int n){
    vector<string> columnStates;  
    generateColumnState("", '#', 0, m, columnStates);  // O(2^m) for generating all possible column states

    dp.resize(n, vector<int>(columnStates.size(), -1));
    // Total Time complexity: O(2^m + (n*m*t^2));
    // space complexity: O(n*t) + O(t)

    // let columnStates.size() == t 
    int result = 0;
    for(int i = 0; i < columnStates.size(); i++) result = (result%mod + func(n-1, i, columnStates)%mod)%mod;

    return result;
}

int func(int remColumn, int prevIdx, vector<string> &columnStates){  
    if(remColumn == 0) return 1;   
    if(dp[remColumn][prevIdx] != -1) return dp[remColumn][prevIdx];
     
    int ways = 0;  // Time complexity: O((n*t) * (m*t)) an n*t total states of dp and m*t is the worst case for calling the bool check() function
    string prevState = columnStates[prevIdx];

    for(int i = 0; i < columnStates.size(); i++){  
        if(i == prevIdx) continue; // as we can't take same state as previous
        string currState = columnStates[i];
        if(check(prevState, currState)) ways = (ways%mod + func(remColumn-1, i, columnStates)%mod)%mod;
    }

    return dp[remColumn][prevIdx] = ways;  
}

bool check(string prevState, string currState){  // O(m) this check whether the current state can be present adjacent to the previous state of the column of the grid
    for(int i = 0; i < prevState.size(); i++) if(prevState[i] == currState[i]) return false;
    return true;
}


//******************************* Alternate approach using Bit-masking *******************************//

int colorTheGrid(int m, int n){
    dp.resize(1000+2, vector<int>(1023, -1)); // have taken maxspace which can be required in worst case
    // dimension of memoization state = No of Columns * Color combinations per column So, dp = 1000 * 1023 size
    
    // Cell per column = No of rows = 5
    // To represent 5 colors, each of 2 bits, total bits required = 10 bits
    // Max value with 10 bits (all set-bits) = 1023

    // 1023 --> 4^5 generalize as 4^m and 1000 generalize as n
    // Time complexity: O(n * (4^m) * (2^m)) 
    // n*(4^m) for total dp states computation and for each computation we have to traverse to all the rows of that column again and again to get the all possible ways
    
    return solve(m, n, 0, 0, 0, 0);
}

int solve(int &rows,int &cols,int currRow, int currCol ,int curr_state, int prev_state){
    if(currCol == cols) return 1;   // Valid Painting Combination

    if(currRow == rows) return solve(rows, cols, 0, currCol + 1, 0, curr_state);  
    //Goto next column --> currRow = 0, curr_state = 0, prev_state = curr_state

    if(currRow == 0 && dp[currCol][prev_state] != -1) return dp[currCol][prev_state];
    // if you are starting to make a new column then first check whether the ans is already computed for currCol and prev_state 

    int up_color = 0;
    if(currRow > 0) up_color = curr_state & 3;
    int left_color = (prev_state >> ((rows - currRow - 1) * 2)) & 3;
    // masking with 3 i.e 11 in binary, just gets the pair bits in which we are interested. This turns OFF more significant pair bits.

    int ways = 0;
    for(int color = 1; color <= 3; color++){  // Try all colors
        if(color != up_color && color != left_color)
            ways = (ways + solve(rows ,cols, currRow+1, currCol, (curr_state<<2) + color, prev_state))%mod;
            // (curr_state<<2) + color --> this  is doing to add extra color 
    }

    if(currRow == 0) dp[currCol][prev_state] = ways;  // store only when currRow = 0

    return ways;
}
