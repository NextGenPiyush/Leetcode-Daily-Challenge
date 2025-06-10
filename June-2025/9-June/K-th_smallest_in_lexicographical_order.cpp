#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/?envType=daily-question&envId=2025-06-09

int findKthNumber(int n, int k); // Leetcode-440
void func(long long curr, int n, int k, int &count, int &result); 

int main(){
    
    // Approach-1: Calculate the vector of lexicographical numbers then return (k-1)th index element from the vector as we need the kth lexicographical number (bad approach)
    // Time complexity: O(n) --> TLE in this case 
    // space complexity: O(n) + O(digits) --> MLE in this case 

    // Approach-2: use the same approach but this time don't store elements in the vector, use a curr varible and as soon as curr == k means we get our kth lexicographical number
    // Time complexity: O(n) --> TLE in this case
    // space complexity: O(digits) 
    
    // Approach-3: Most optimized
    
    return 0;
}

//********************************************* Appproach-2 *********************************************//

int findKthNumber(int n, int k){
    int result = 0;
    int count = 0;  // indicate the no of element already taken in the lexicographical order

    // make call from every number to maintain the lexicographical order
    for(long long num = 1; num <= 9; num++) func(num, n, k, count, result);
    return result;
}

void func(long long curr, int n, int k, int &count, int &result){
    if(curr > n) return; 
    
    count++; // if (curr<=n) means we have to count it 
    if(count == k){  // means we have taken k lexicographical numbers 
        result = curr; 
        return;
    }

    for(int nextDigit = 0; nextDigit <= 9; nextDigit++){  // next digits 
        long long nextnum = curr * 10 + nextDigit;  // moving to the next 
        if(nextnum <= n) func(nextnum, n, k, count, result);
        else break;
    }
}

//******************************************** Approach-3 ********************************************//

int findKthNumber(int n, int k){
    int curr = 1;  
    k -= 1;  // subtracted 1 because we have consider number 1 already

    // time complexity: O(log(n) to-base-10)^2
    // space complexity: O(log(n) to-base-10)

    while(k > 0){ 
        int count = Count(curr, curr+1, n);  // if count of total numbers between two simultaneous digits lexicographically less than the value of k it means skip whole subtree 
        if(count <= k){              
            curr++;  
            k -= count;  // skipping subtree
        }
        else{
            curr *= 10;  // move to the next level
            k -= 1;    // subtracted one as we have come down by skipping one number
        } 
    }

    return curr;
}

int Count(long curr, long next, int n){  // O(log(n) to-base-10) as we are multiplying with 10 to reach the n
    int countNum = 0;

    while(curr <= n){
        countNum += (next - curr);  // counting lexicographical number between the curr and next number 
        curr *= 10; // moving to the next level
        next = next*10;  
        next = min(next, long(n+1)); // to handle the case whene there is no completion of the numbers at a paritcular level 
    }

    return countNum;
}
