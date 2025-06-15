#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/koko-eating-bananas/

int minEatingSpeed(vector<int>& piles, int h); // Leetcode-875

int main(){
    
    
    
    return 0;
}

int minEatingSpeed(vector<int>& piles, int h){
    int n = piles.size(); 

    // time complexity: O(n*log(max_banana) + n) and space complexity: O(1)

    int max_banana = *max_element(piles.begin(), piles.end());  // O(n)
    if(h == n) return max_banana;

    long low = 1, high = max_banana;
    long result;
    while(low <= high){  // O(log(max_banana)*n)
        long mid = low + (high-low)/2;
        if(isValid(mid, piles, h)){
            result = mid;  // we got our ans but try to check for the lesser value of banana eating speed
            high = mid - 1;
        }
        else low = mid + 1; // increase the speech of eating banana per hour
    }

    return result;
}

bool isValid(long banana, vector<int> &piles, int h){
    int n = piles.size();
    long count = 0;
    for(int i = 0; i < n; i++) count += (piles[i] + banana - 1)/banana;  // O(n)
    return count <= h;
}