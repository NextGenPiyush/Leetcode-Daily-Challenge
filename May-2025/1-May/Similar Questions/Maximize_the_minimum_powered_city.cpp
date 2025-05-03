#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximize-the-minimum-powered-city/description/
long long maxPower(vector<int>& stations, int r, int k);  // Leetcode-2528
bool isGood(vector<int> stations, int r, long long minPowerRequired, int additionalStations);

int main(){



    return 0;
}

long long maxPower(vector<int>& stations, int r, int k){
    int n = stations.size();
    long long left = 0;
    long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;
    long long ans = 0;

    while(left <= right){  // Time Complexity: O(n * logn)
        long long mid = (left + right)/2;
        if(isGood(stations, r, mid, k)){
            ans = mid; // This is the maximum possible minimum power so far
            left = mid + 1; // Search for a larger value in the right side
        } 
        else right = mid - 1; // Decrease minPowerRequired to need fewer additional power stations
    }

    return ans;
}

bool isGood(vector<int> stations, int r, long long minPowerRequired, int additionalStations){
    int n = stations.size();
    long long windowPower = accumulate(stations.begin(), stations.begin()+r, 0LL);
    // windowPower storing stations from [0...r-1]

    for(int i = 0; i < n; i++){  // Time complexity: O(n)
        if(i+r < n) 
            windowPower += stations[i + r];  // we have to add this to complete the window
            // now, windowPower stores sum of power stations from [i-r..i+r]

        if(windowPower < minPowerRequired){
            long long needed = minPowerRequired - windowPower;
            if(needed > additionalStations) return false;  // Not enough additional stations to plant

            // Plant the stations in the farthest city in the range to cover as many cities as possible
            stations[min(n - 1, i + r)] += needed;
            windowPower = minPowerRequired;
            additionalStations -= needed;
        }

        if(i-r >= 0) windowPower -= stations[i - r]; // in next iteration this will not come in new window
    }

    return true;
}