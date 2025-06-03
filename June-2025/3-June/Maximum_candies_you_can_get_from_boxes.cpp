#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/?envType=daily-question&envId=2025-06-03

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes); // Leetcode-1298

int main(){

    
    
    return 0;
}

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes){
    queue<int> q;  // O(n)
    unordered_set<int> st;  // O(n)
    unordered_set<int> visited;  // O(n)
    int ans = 0;

    // Time complexity: O(n^2)
    // space complexity: O(3n)

    for(auto box : initialBoxes){  // O(n) where n is the total no of boxes
        if(status[box] == 1){
            q.push(box);  // we can open the box
            visited.insert(box);
        }
        else st.insert(box);  // as the box is not opne we have stored it in set as reserved box
    }

    while(!q.empty()){
        int box = q.front();
        q.pop();
        ans += candies[box];

        for(auto currBox : containedBoxes[box]){  // O(n^2)
            if(visited.find(currBox) == visited.end()){
                if(status[currBox] == 1){
                    q.push(currBox);  // we can open the box
                    visited.insert(currBox);
                } 
                else st.insert(currBox);  // store the reserved currBox 
            }
        }

        for(auto currKey : keys[box]){  // O(n^2)
            if(status[currKey] == 0){
                status[currKey] = 1;
                if(st.find(currKey) != st.end() && visited.find(currKey) == visited.end()){
                    q.push(currKey);  // means we have find the key for resereved box
                    visited.insert(currKey);
                    st.erase(currKey);
                }
            }
        }
    }

    return ans;
}
