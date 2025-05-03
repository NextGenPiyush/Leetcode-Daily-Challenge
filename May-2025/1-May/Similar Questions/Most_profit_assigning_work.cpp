#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/most-profit-assigning-work/description/
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker); // Leetcode-826

int main(){
    
    
    
    return 0;
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
    int n = difficulty.size();
    int m = worker.size();   // Total Time complexity: O(n) + O(n*logn) + O(m*logn)

    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) v.push_back({difficulty[i], profit[i]});  // O(n)
    sort(v.begin(), v.end());  // O(n*logn)

    for(int i = 0; i < n; i++){  // O(n)
        difficulty[i] = v[i].first; 
        profit[i] = v[i].second;
    }

    vector<int> maxProfit(n,0);  // ith index indicate the maxProfit till now in the vector
    maxProfit[0] = profit[0];
    for(int i = 1; i < n; i++) maxProfit[i] = max(maxProfit[i-1], profit[i]); // O(n)

    int total_profit_earn = 0;

    for(int i = 0; i < m; i++){  // O(m*logn)
        auto it = upper_bound(difficulty.begin(), difficulty.end(), worker[i]) - difficulty.begin();
        if(it == 0) continue; // workers can't do the task
        else if(it == n || difficulty[it-1] <= worker[i]) total_profit_earn += maxProfit[it-1];
    }

    return total_profit_earn;
}

//**************************************** Alternate Approach ****************************************//

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
    int n = difficulty.size();
    int m = worker.size();      // Total Time complexity: O((n+m)*logn + m*logm)

    priority_queue<pair<int,int>> pq;  // maxheap
    for(int i = 0; i < n; i++) pq.push({profit[i], difficulty[i]}); // O(n*logn)

    sort(worker.begin(), worker.end(), greater<int>()); // sorting in descending order O(m*logm)

    int i = 0;
    int total_profit = 0;
    while(i < m && !pq.empty()){  // O(m*logn)
        if(pq.top().second > worker[i]) pq.pop();  // this task cannot be done by i-th worker O(logn)
        else{
            total_profit += pq.top().first;
            i++;
        }
    }

    return total_profit;
}

//**************************************** Alternate Approach ****************************************//

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
    int n = difficulty.size();
    int m = worker.size();        // Time complexity: O(n*logn + m*logm + n + m)
    
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++) vec.push_back({difficulty[i], profit[i]}); // O(n)
    sort(begin(vec), end(vec));  // O(n*logn)
    sort(begin(worker), end(worker));  // O(m*logm)

    int totalProfit = 0;
    int j = 0; //pointing to vec
    int maxProfit = 0;

    for(int i = 0; i < m; i++){  // O(n+m)
        while(j < n && worker[i] >= vec[j].first){
            maxProfit = max(maxProfit, vec[j].second);
            j++;
        }
        totalProfit += maxProfit;
    }

    return totalProfit;
}