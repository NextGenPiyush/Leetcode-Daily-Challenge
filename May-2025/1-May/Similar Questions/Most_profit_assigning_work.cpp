#include<bits/stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker); // Leetcode-826

int main(){
    
    
    
    return 0;
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
    int n = difficulty.size();
    int m = worker.size();

    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) v.push_back({difficulty[i], profit[i]});
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        difficulty[i] = v[i].first; 
        profit[i] = v[i].second;
    }

    vector<int> maxProfit(n,0);  // ith index indicate the maxProfit till now in the vector
    maxProfit[0] = profit[0];
    for(int i = 1; i < n; i++) maxProfit[i] = max(maxProfit[i-1], profit[i]);

    int total_profit_earn = 0;

    for(int i = 0; i < m; i++){
        auto it = upper_bound(difficulty.begin(), difficulty.end(), worker[i]) - difficulty.begin();
        if(it == 0) continue; // workers can't do the tast
        else if(it == n || difficulty[it-1] <= worker[i]) total_profit_earn += maxProfit[it-1];
    }

    return total_profit_earn;
}