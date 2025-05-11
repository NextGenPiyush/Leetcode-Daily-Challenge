#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximum-product-of-two-digits/

int maxProduct(int n); // Leetcode-3536

int main(){

    // to get the maximum possible product we have multiplied the largest digits of the num

    return 0;
}

int maxProduct(int n){
    int maxi = 0, smaxi = 0;

    while(n != 0){  // Time complexity: O(digits)
        int num = n%10;
        if(maxi < num){
            smaxi = maxi;
            maxi = num;
        }
        else if(smaxi < num) smaxi = num;
        n = n/10;
    }
    
    return maxi*smaxi;
}