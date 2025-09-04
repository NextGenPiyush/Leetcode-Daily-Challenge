#include<bits/stdc++.h>
using namespace std;

// Problem link: https://leetcode.com/problems/find-closest-person/?envType=daily-question&envId=2025-09-04

int findClosest(int x, int y, int z); // Leetcode-3516

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    

    return 0;
}

int findClosest(int x, int y, int z){
    if(abs(z-x) > abs(z-y)) return 2;        // Time complexity: O(1)
    else if(abs(z-x) < abs(z-y)) return 1;   // space complexity; O(1)
    else return 0;
}