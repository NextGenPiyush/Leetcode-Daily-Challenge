#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/
string answerString(string word, int numFriends);  // Leetcode-3403

int main(){

    
    
    return 0;
}

string answerString(string word, int numFriends){
    int n = word.size();
    if(numFriends == 1) return word;  // Time complexity: O(n^2) and space complexity: O(1)

    string result;
    int longestPossibleString = n - numFriends + 1;
    
    for(int i = 0; i < n; i++){  // O(n)
        int canTakenLength = min(longestPossibleString, n-i);
        result = max(result, word.substr(i, canTakenLength));  // O(n) due to substr function 
    }

    return result;
}

//**************************************** Alternate Approach ****************************************//

int bestStartingPoint(string &word){
    int n = word.size();
    int i = 0;  // best strating point
    int j = 0; // will be used to traverse
 
    while(j < n){  // Time complexity: O(n)
        int k = 0;
        while(j + k < n && word[i+k] == word[j+k]) k++;  // skipping equal characters
        if(j + k < n && word[j+k] > word[i+k]) i = j++;  // updated best position
        else j = j + k + 1; // skipping already checked characters
    } 
}

string answerString(string word, int numFriends){
    int n = word.size();
    if(numFriends == 1) return word;  // Time complexity: O(n) and space complexity: O(1)

    int i = bestStartingPoint(word);
    int longestPossibleLength = n - numFriends + 1;
    int canTakePossible = min(longestPossibleLength, n-i);

    return word.substr(i, canTakePossible);
}
