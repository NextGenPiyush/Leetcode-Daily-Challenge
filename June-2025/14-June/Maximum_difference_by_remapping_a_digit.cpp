#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/editorial/?envType=daily-question&envId=2025-06-14

int minMaxDifference(int num); // Leetcode-2566

int main(){
    
    
    
    return 0;
}

int minMaxDifference(int num){
    string max_string = to_string(num);
    string min_string = max_string;

    // Time complexity: O(digits) ~ O(log10(num)) which in worst case will be O(8) ~ O(1) constant
    // space complexity: O(1)

    // According to the rules of digits, to generate the maximum value, we should replace digits to make the number as large as possible, typically by replacing some digit with '9'
    int idx = max_string.find_first_not_of('9');  // O(d)
    if(idx != string::npos){
        char ch = max_string[idx];
        replace(begin(max_string), end(max_string), ch, '9');  // O(d)
    }

    // To generate the minimum value, we should do the opposite and replace some digit with '0' to make the number as small as possible
    char ch = min_string[0]; //given input will not have leading zero
    replace(begin(min_string), end(min_string), ch, '0');  // O(d)

    return stoi(max_string) - stoi(min_string);
}