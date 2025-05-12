#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=daily-question&envId=2025-05-12
vector<int> findEvenNumbers(vector<int>& digits); // Leetcode-2094

int main(){



    return 0;
}

vector<int> findEvenNumbers(vector<int>& digits){
    vector<int> num(10, 0);
    for(int d : digits) num[d]++;    // Total Time complexity: O(n) + O(1000)

    vector<int> ans;
    for(int i = 100; i <= 998; i += 2){   // O(1000)
        if(isValid(i, num)) ans.push_back(i);
    }

    return ans;
}

bool isValid(int number, vector<int> count){
    int d1 = number / 100;
    int d2 = (number / 10) % 10;
    int d3 = number % 10;

    if(count[d1] == 0) return false;
    else count[d1]--;

    if(count[d2] == 0) return false;
    else count[d2]--;

    if(count[d3] == 0) return false;
    else count[d3]--;

    return true;
}

//************************************* Alternate Solution *************************************//

vector<int> findEvenNumbers(vector<int>& digits){
    unordered_set<int> st;    // Time complexity: O(n^3) + O(s*logs)
    int n = digits.size();

    for(int i = 0; i < n; i++){     // taking 3 pointers and traversing into the digit
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i == j || j == k || i == k) continue; // if any two pointer point the same num then continue
                int num = digits[i]*100 + digits[j]*10 + digits[k];
                if(num >= 100 && num%2 == 0) st.insert(num);
            }
        }
        }
        
    vector<int> result(begin(st), end(st));  
    // space complexity: O(nC3) = O(s) in worst case we have to select 3 num from the digit vector

    sort(begin(result), end(result));  // O(s*logs)
    return result;
}

//************************************* Alternate Solution *************************************//

vector<int> findEvenNumbers(vector<int>& digits){
    vector<int> result;   // Time complexity: O(1)

    vector<int> mp(10, 0);  // space complexity: o(1)
    for(int &digit : digits) mp[digit]++;

    for(int i = 1; i <= 9; i++){  // fist digit can be from 1-9 O(9)
        if(mp[i] == 0) continue;
        mp[i]--;

        for(int j = 0; j <= 9; j++){  // second digit can be from 0-9 O(10)
            if(mp[j] == 0) continue;
            mp[j]--;

            for(int k = 0; k <= 8; k += 2){  // third digit must be 0,2,4,6,8 for teh digit to be even O(5)
                if(mp[k] == 0) continue;
                mp[k]--;
                
                int num = i*100 + j*10 + k;
                result.push_back(num);
                mp[k]++; // make sure to add element back so the we can again use it at other position
            }
            mp[j]++;
        }
        mp[i]++;
    }

    return result;
}
