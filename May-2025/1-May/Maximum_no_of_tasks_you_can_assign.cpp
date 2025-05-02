#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/?envType=daily-question&envId=2025-05-01

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength); // Leetcode-2071
bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid); 

int main(){
    
    
    return 0;
}

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength){
    int n = tasks.size(), m = workers.size();
    
    sort(tasks.begin(), tasks.end());  // sorting in ascending order O(n*logn)
    sort(workers.begin(), workers.end(), greater<int>());  // sorting in descending order O(m*logm)

    // Total Time complexity: O(n*logn + m*logm + (logn * (logm + m*logm*logm))
    
    int result = 0;   // we are going to apply binary search on the ans
    // we will take low as 0 tasks completed and high as all task completed and check if we can complete (mid) number of task. If yes then low = mid+1 and if not then high = mid-1 
    
    int low = 0, high = min(n,m);  // Time complexity: O(logn) considering we have more workers than tasks
    while(low <= high){
        int mid = low + (high-low)/2;
        if(check(tasks, workers, pills, strength, mid)){   // O(m*logm)
            result = mid;
            low = mid+1;
        }
        else high = mid-1;
    }  
    
    return result;
}

bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
    int pillsUsed = 0;
    multiset<int> st(workers.begin(), workers.end() + mid);  // for insertion and deletion O(logm)

    for(int i = mid-1; i >= 0; i--){   // worstcase Time complexity: O(m * logm * logm)
          
        int required = tasks[i];
        auto it = prev(st.end());  // last element of the st<nultiset>

        if(*it >= required) st.erase(it); // means maximum strength task assigned to the maximum strength worker 
        else if(pillsUsed >= pills) return false; // means on requirement we dont have any pills left 
        else{
            // if we have to assign the pill to complete the task, then why not give it to the worker who can just do that task after taking pill rather than the stongest worker
            auto weakestWorkerIt = st.lower_bound(required - strength);  // O(logm)

            if(weakestWorkerIt == st.end()) return false;  // means even the strongest person can't 
            else{
                st.erase(weakestWorkerIt);  // means we have used one extra pill O(logm)
                pillsUsed++;
            }
        } 
    }

    return true; 
}