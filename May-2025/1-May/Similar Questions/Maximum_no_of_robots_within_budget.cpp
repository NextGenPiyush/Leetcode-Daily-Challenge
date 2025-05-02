#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximum-number-of-robots-within-budget/description/

int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget); // Leetcode-2398
bool check(vector<int>& chargeTimes, vector<long long>& prefixSum, long long budget, int k);

int main(){

    
    
    return 0;
}

int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget){
    int n = chargeTimes.size();
    
    vector<long long> prefixSum(n+1, 0);
    for(int i = 0; i < n; ++i) prefixSum[i + 1] = prefixSum[i] + runningCosts[i];  // O(n)

    int result = 0;  // applying binary search on the result
    int low = 1, high = n;  

    while(low <= high){  // Time complexity: O(n * logn)
        int mid = low + (high-low)/2;
        if(check(chargeTimes, prefixSum, budget, mid)){  // O(n)
            result = mid;
            low = mid+1;                // Total Time Complexity: O(n) + O(n*logn)
        }
        else high = mid-1;
    }

    return result;
}

bool check(vector<int>& chargeTimes, vector<long long>& prefixSum, long long budget, int k){
    int n = chargeTimes.size();
    long long currentCost = 0;

    int n = chargeTimes.size();
    deque<int> dq;

    for(int i = 0; i < n; ++i){  // O(n)
        while(!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[i]) dq.pop_back(); 
        dq.push_back(i);  // pushing in such a way that largest element in the window in at front

        if(i >= k-1){
            long long sum = prefixSum[i] - (i-k >= 0 ? prefixSum[i-k] : 0);
            if(dq.front() <= i-k) dq.pop_front();  // pop because fornt index is from the previous window

            long long totalCost = chargeTimes[dq.front()] + k * sum;
            if(totalCost <= budget) return true;
        }
    }

    return false;
}