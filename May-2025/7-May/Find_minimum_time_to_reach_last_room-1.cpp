#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // down, up, right, left

int minTimeToReach(vector<vector<int>>& moveTime);  // Leetcode-3341

int main(){



    return 0;
}



int minTimeToReach(vector<vector<int>>& moveTime){
    int m = moveTime.size();
    int n = moveTime[0].size();

    vector<vector<int>> result(m, vector<int>(n, INT_MAX)); // Store the minimum time to reach each room
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap; // Min-heap to get the room with the earliest time

    result[0][0] = 0; // Starting point, time is 0
    minHeap.push({0, {0, 0}}); // Push the starting room into the heap

    while(!minHeap.empty()) {
        int currTime = minHeap.top().first;  // Current time to reach the room
        auto cell = minHeap.top().second;
        int i = cell.first;  // Current row
        int j = cell.second; // Current col

        minHeap.pop();
            
        if(i == m - 1 && j == n - 1) return currTime;  //we've reached the bottom-right corner, return the time

        // Explore the 4 adjacent directions
        for(auto &dir : directions){
            int nextRow = i + dir[0];
            int nextCol = j + dir[1];

            // Check if the next room is within bounds
            if(nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n) {
                // Calculate the time to reach the next room (wait time + movement time)
                int wait = max(moveTime[nextRow][nextCol] - currTime, 0);
                int arrivalTime = currTime + wait + 1;

                // If a faster route to the next room is found, update and push to the min-heap
                if(result[nextRow][nextCol] > arrivalTime) {
                    result[nextRow][nextCol] = arrivalTime;
                    minHeap.push({arrivalTime, {nextRow, nextCol}});
                }
            }
        }
    }

    return -1; // If no valid path (shouldn't happen per problem guarantee)
}