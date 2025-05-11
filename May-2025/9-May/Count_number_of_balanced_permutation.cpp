#include<bits/stdc++.h>
using namespace std;

int n;
int totalDigitSum;
int M = 1e9 + 7;
long long totalPermPossible = 0;

vector<vector<vector<int>>> dp;

int findPower(long long a, long long b){  // Binary exponentiation
    if(b == 0) return 1;
    long long half = findPower(a, b/2);
    long long result = (half * half) % M;
    if(b % 2 == 1) result = (result * a) % M;
    return result;
}

int countBalancedPermutations(string num); // Leetcode-3343
int solve(int digit, int evenIndexDigitsCount, int currSum, vector<int>& freq, vector<long long>& fermatFact);

int main(){    

    // very good question based on dp with combinatorics
    // try again by yourself

    return 0;
}

int countBalancedPermutations(string num){
    sort(num.begin(), num.end()); //Sorting helps next_permutation to find all permutation, so we need to start from smallest (hence sorted)
    unordered_set<string> seen;
    int count = 0;

    do{                 // Time complexity: O(n*n!)
        if(seen.count(num)) continue;   // we are generating all the ppermutations ans traversing all to check
        seen.insert(num);

        int evenSum = 0, oddSum = 0;
        for(int i = 0; i < num.size(); ++i){
            int digit = num[i] - '0';
            if(i % 2 == 0) evenSum += digit;
            else oddSum += digit;
        }
        if(evenSum == oddSum) count++;
    } while(next_permutation(num.begin(), num.end()));
    
    return count;
}

//***************************************** Alternae approach *****************************************//

int solve(int digit, int evenIndexDigitsCount, int currSum, vector<int>& freq, vector<long long>& fermatFact){
    if(digit == 10){
        if(currSum == totalDigitSum/2 && evenIndexDigitsCount == (n+1)/2) return totalPermPossible;
        return 0; 
    }   
    if(dp[digit][evenIndexDigitsCount][currSum] != -1) return dp[digit][evenIndexDigitsCount][currSum];

    long long ways = 0;

    for(int count = 0; count <= min(freq[digit], (n+1)/2 - evenIndexDigitsCount); count++){ 
        // we have taken minimum as there can be the case where freq of the digit is more than the remaning even indices
        int evenPosCount = count;  // taking count no of digits at even position
        int oddPosCount = freq[digit] - count;

        long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount])% M; 
        // div = ((1/(evenPoscount)! )%mod* (1/(oddPosCount)!)%mod)&mod

        long long val = solve(digit+1, evenIndexDigitsCount + evenPosCount, currSum + digit*count, freq, fermatFact);

        ways = (ways + (val * div) % M) % M;
    }

    return dp[digit][evenIndexDigitsCount][currSum] = ways;
}

int countBalancedPermutations(string num){
    n = num.length();
    totalDigitSum = 0;

    vector<int> freq(10, 0);
    for(int i = 0; i < n; i++){
        totalDigitSum += num[i] - '0';
        freq[num[i] - '0']++;
    }

    if(totalDigitSum % 2 != 0) return 0;

    //Precomputing factorial
    vector<long long> fact(n+1, 1);
    fact[0] = 1; fact[1] = 1;
    for(int i = 2; i <= n; i++) fact[i] = (fact[i-1] * i) % M;

    //Precomputing FermatFactorial (inverse factorial --- (1/x)%M)
    vector<long long> fermatFact(n+1, 1);
    for(int i = 0; i <= n; i++) fermatFact[i] = findPower(fact[i], M-2) % M;

    totalPermPossible = (1LL * fact[(n+1)/2] * fact[n/2]) % M;

    int digit = 0;
    int evenIndexDigitsCount = 0;  // Time complexity: O(10* (n+1)/2 * (9*80/2) * n)
    int currSum = 0;
    dp.resize(10, vector<vector<int>>((n + 1) / 2 + 1, vector<int>(totalDigitSum + 1, -1)));
    
    return solve(digit, evenIndexDigitsCount, currSum, freq, fermatFact);
}