#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-15

int maxDiff(int num);  // Leetcode-1432

int main(){
    
    
    
    return 0;
}

int maxDiff(int num){
    int n = log10(num) + 1;  // n --> no of digits in the given number
    string min_string = to_string(num);
    string max_string = min_string;

    auto replace = [](string& s, char x, char y){  // lamda function for replacing all occurence of x to y 
        for(char& digit : s) if(digit == x) digit = y;
    };

    // time complexity: O(n) where n is the number of digits which will be equal to the log10(num) + 1, in worst case: O(8) ~ O(1) constant
    // space complexity: O(1)

    // To find the largest number, we iterate through each digit of num from left to right (most significant to least significant). If the digit at the current position is not 9, we replace all occurrences of that digit with 9 to obtain the largest possible number. 
    int idx = max_string.find_first_not_of('9');  // give first index where x is not present //O(n)
    if(idx != string::npos){
        char ch = max_string[idx];
        // replace(begin(max_string), end(max_string), ch, '9');  // O(n)
        replace(max_string, ch, '9');  // O(n)
    }

    // To find the smallest number, we again iterate through each digit of num from left to right. If the digit at the current position is not 0, we replace all occurrences of that digit with 0 to obtain the smallest possible number. we must handle the issue of leading zeros carefully.
    for(int i = 0; i < min_string.length(); i++){  // O(n)
        char ch = min_string[i];
        if(i == 0 && ch != '1'){
            // replace(min_string.begin(), min_string.end(), ch, '1');
            replace(min_string, ch, '1');
            break;
        }
        else if(ch != '0' && ch != min_string[0]){
            // replace(min_string.begin(), min_string.end(), ch, '0');
            replace(min_string, ch, '0');
            break;
        }
    }

    return stoi(max_string) - stoi(min_string);
}

//****************************************** Alternate Approach ******************************************//

 int maxDiff(int num){
    auto change = [&](int x, int y){  // lamda function for replacing all oxxurence of x to y in the number
        string num_string = to_string(num);
        for(char& digit : num_string) if(digit - '0' == x) digit = '0' + y; //O(digits)
        return num_string;
    };

    // Time complexity: O(1) as largest poossible complexity can be O(100*digits) == O(d*d*log10(num))
    // space complexity: O(1)

    int min_num = num;
    int max_num = num;

    // According to the problem description, we can arbitrarily choose two digits x and y, and replace all occurrences of x in num with y. Since both x and y range from 0 to 9, there are at most 10×10=100 different replacement methods.
    for(int x = 0; x < 10; ++x){  // O(100*digits)
        for(int y = 0; y < 10; ++y){
            string res = change(x, y);
            if(res[0] != '0'){  // Check if there are leading zeros
                int res_int = stoi(res);
                min_num = min(min_num, res_int);  // cheching for min number
                max_num = max(max_num, res_int);  // checking for max number
            }
        }
    }

    return max_num - min_num;
}