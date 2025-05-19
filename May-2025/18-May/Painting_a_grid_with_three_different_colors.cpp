#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/?envType=daily-question&envId=2025-05-18
int mod = 1e9 + 7;
vector<vector<int>> dp;

int colorTheGrid(int m, int n); // Leetcode-1931
void generateColumnState(string curr, char prevChar, int length, int rows, vector<string> &columnStates);
int func(int remColumn, int prevIdx, vector<string> &columnStates);
bool check(string prevState, string currState);

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