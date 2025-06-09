#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/lexicographical-numbers/editorial/?envType=daily-question&envId=2025-06-08

vector<int> lexicalOrder(int n); // Leetcode-386

int main(){
    

    
    return 0;
}

//********************************************** Approach-1 **********************************************//

vector<int> lexicalOrder(int n){
    vector<int> lexicographicalNumbers;
    // Start generating numbers from 1 to 9
    for(int start = 1; start <= min(n,9) ; ++start) generateLexicalNumbers(start, n, lexicographicalNumbers);

    // time complexity: O(n) The algorithm generates all numbers from 1 to n in lexicographical order. Each number is visited exactly once and added to the result list
    // space complexity: O(log(n)-to-base-10); --> O(no of digits) which cab be considered as O(1)

    return lexicographicalNumbers;
}

void generateLexicalNumbers(int currentNumber, int limit, vector<int>& result){
    if(currentNumber > limit) return; // If the current number exceeds the limit, stop recursion
    result.push_back(currentNumber); // Add the current number to the result

    // Try to append digits from 0 to 9 to the current number
    for(int nextDigit = 0; nextDigit <= 9; ++nextDigit){
        int nextNumber = currentNumber * 10 + nextDigit;
            
        // If the next number is within the limit, continue recursion
        if(nextNumber <= limit) generateLexicalNumbers(nextNumber, limit, result); 
        else break;  // No need to continue if nextNumber exceeds limit
    }
}

//********************************************* Approach-2 *********************************************//

vector<int> lexicalOrder(int n){
    vector<int> lexicographicalNumbers;
    int currentNumber = 1;

    // Time complexity: O(n)
    // Each iteration involves constant-time operations (checking conditions and updating currentNumber)

    // space complexity: O(1)

    for(int i = 0; i < n; ++i){ // Generate numbers from 1 to n
        lexicographicalNumbers.push_back(currentNumber);

        // If multiplying the current number by 10 is within the limit, do it
        if(currentNumber * 10 <= n) currentNumber *= 10; // go deeper into the tree of numbers if you want to maintain the lexicographical order
        else{
            // Adjust the current number by moving onto upper levels 
            while(currentNumber % 10 == 9 || currentNumber >= n) currentNumber /= 10; // Remove the last digit
            // removing last digit means we are going back to upper level
            currentNumber += 1;  // after removing the last digit increment the number by 1 to add the next lexicographical number
        }
    }

    return lexicographicalNumbers;
}