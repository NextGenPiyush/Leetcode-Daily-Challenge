#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=daily-question&envId=2025-05-05

int mod = 1e9 + 7;
vector<vector<int>> dp;

int numTilings(int n); // Leetcode-790
int func(int idx, bool open, int n);
int fbu(int n);

int solve(int n); // tricky to understand

int main(){
    
    

    return 0;
}

int numTilings(int n){
    int idx = 0;
    bool open = false;

    dp.resize(n+1, vector<int>(2, -1));
    return func(idx, open, n)%mod;

    // return fbu(n);  
}

int func(int idx, bool open, int n){  // top-down approach
    if(idx > n) return 0;
    if(idx == n) return open ? 0 : 1;

    if(dp[idx][open] != -1) return dp[idx][open]; // Time complexity: O(n)
    long long ans = 0;                      

    if(open == false){ // means there is no opening yet
        long long vertical_placing = func(idx+1, false, n);
        long long horizontal_placing = func(idx+2, false, n);
        long long tromino_placing = 2*func(idx+2, true, n); // we have opened the tromino

        ans = (ans%mod + vertical_placing%mod + horizontal_placing%mod + tromino_placing%mod)%mod;
    }

    else{  // means tromino is already opened
        long long tromino_placing_1 = func(idx+1, false, n); // we have closed the tromino using reversing and flipping
        long long tromino_placing_2 = func(idx+2, false, n); // we have closed the tromino using reversing only
        long long horizontal_placing = func(idx+2, true, n); // tromino is still open 

        ans = (ans%mod + tromino_placing_1%mod + tromino_placing_2%mod + horizontal_placing%mod)%mod;
    }

    return dp[idx][open] = ans%mod;
}

int fbu(int n){   // Bottom-up approach
    vector<vector<int>> dp(n+2, vector<int>(2, 0));
    dp[n][0] = 1;  // Base-case

    for(int idx = n-1; idx >= 0; idx--){
        for(int open = 0; open <= 1; open++){  // Time complexity: O(n)
            long long ans = 0;

            if(open == 0){ // means there is no opening yet
                long long vertical_placing = dp[idx+1][0];
                long long horizontal_placing = dp[idx+2][0];
                long long tromino_placing = 2*dp[idx+2][1]; // we have opened the tromino

                ans = (ans%mod + vertical_placing%mod + horizontal_placing%mod + tromino_placing%mod)%mod;
            }

            else{  // means tromino is already opened
                long long tromino_placing_1 = dp[idx+1][0]; // closed the tromino using reversing and flipping
                long long tromino_placing_2 = dp[idx+2][0]; // we have closed the tromino using reversing only
                long long horizontal_placing = dp[idx+2][1]; // tromino is still open 

                ans = (ans%mod + tromino_placing_1%mod + tromino_placing_2%mod + horizontal_placing%mod)%mod;
            }

            dp[idx][open] = ans%mod;
        }
    }

    return dp[0][0];
}

//***************************************** Alternate Approach *****************************************//

int solve(int n){
    if(n == 1 || n == 2) return n;

    vector<int> t(n+1, 0);
    t[1] = 1;  t[2] = 2;  t[3] = 5;
    for(int i = 4; i <= n; i++) t[i] = ((2*t[i-1]) % mod + t[i-3] % mod) % mod;

    return t[n];
}