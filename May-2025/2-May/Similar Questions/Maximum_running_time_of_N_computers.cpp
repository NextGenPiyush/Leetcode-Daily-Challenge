#include<bits/stdc++.h>
using namespace std;

long long maxRunTime(int n, vector<int>& batteries);  // Leetcode-2141
bool check(vector<int> &batteries, long long time, int n);

int main(){

    
    
    return 0;
}

long long maxRunTime(int n, vector<int>& batteries){
    int m = batteries.size();
    long long sum = 0;
    for(auto ele : batteries) sum += ele;  // O(m)

    long long low = *min_element(batteries.begin(), batteries.end());  // O(m)
    long long high = sum/n;

    long long result = 0;  
    // we will apply binary search on the result ranging from min value in the batteries to the sum/n

    while(low <= high){   // O(logk)
        long long mid = low + (high - low)/2;
        if(check(batteries, mid, n)){  // O(m)
            result = mid;
            low = mid+1;              // Total Time complexity: O(m) + O(m) +(m*logk)
        }
        else high = mid-1;
    }

    return result;
}

bool check(vector<int> &batteries, long long time, int n){
    long long target = time*n;  //each computer will run time minutes

    for(auto ele : batteries){  // O(m)
        target -= min((long long)ele, time);
        if(target <= 0) return true;
    }

    return target <= 0;
}