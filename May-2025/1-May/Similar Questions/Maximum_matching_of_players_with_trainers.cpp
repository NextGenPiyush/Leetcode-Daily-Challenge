#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/
int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers); // Leetcode-2410

int main(){

    // Leetcode-455 https://leetcode.com/problems/assign-cookies/
    // this question is exact similar to matching players and trainers

    return 0;
}

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers){
    int n = players.size();
    int m = trainers.size();   // Time complexity: O(n*logn) + O(max(n,m))
 
    sort(players.begin(), players.end());  // O(n*logn)
    sort(trainers.begin(), trainers.end()); // O(n*logn)

    int i = 0, j = 0;
    while(i < n && j < m){  // O(max(n,m))
        if(players[i] <= trainers[j]) i++;  // ith player assignes to a trainer
        j++;  // increment j either player assigned or not
    } 

    return i;
}