#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/relative-ranks/

vector<string> findRelativeRanks(vector<int>& score); // Leetcode-506

int main(){
    
    
    
    return 0;
}

vector<string> findRelativeRanks(vector<int>& score){
    int n = score.size();
    vector<pair<int, int>> v; // {score, index}

    // time complexity: O(n + n*logn(n)) and space complexity: O(n) for storing the score and the index
    for(int i = 0; i < n; ++i) v.push_back({score[i], i});  // O(n)

    // sort(v.rbegin(), v.rend()); // sort in descending order              // O(n*log(n))
    sort(v.begin(), v.end(), greater<int>()); // sort in descending order   // O(n*log(n))

    vector<string> ans(n);
    for(int i = 0; i < n; ++i){ // O(n)
        if(i == 0) ans[v[i].second] = "Gold Medal";
        else if(i == 1) ans[v[i].second] = "Silver Medal";
        else if(i == 2) ans[v[i].second] = "Bronze Medal";
        else ans[v[i].second] = to_string(i + 1);
    }

    return ans;
}

//******************************************* Alternate method *******************************************//

vector<string> findRelativeRanks(vector<int>& score){
    int n = score.size();
    
    // time complexity: O(n*logn + n*logn) and space complexity: O(n) for storing score and index in the heap
    
    priority_queue<pair<int, int>> heap; // Create a max heap of pairs (score, index)
    for (int i = 0; i < n; i++) heap.push({score[i], i}); // O(n*log(n))
    
    vector<string> rank(n);  // Assign ranks to athletes
    
    int place = 1;
    while(!heap.empty()){
        int originalIndex = heap.top().second;
        heap.pop();  // O(n*log(n))
        if(place == 1) rank[originalIndex] = "Gold Medal";
        else if(place == 2) rank[originalIndex] = "Silver Medal";
        else if(place == 3) rank[originalIndex] = "Bronze Medal";
        else rank[originalIndex] = to_string(place);
        place++;
    }
    
    return rank;
}

//******************************************* Alternate method *******************************************//

vector<string> findRelativeRanks(vector<int>& score){
    int n = score.size();

    // time complexity: O(n+m) and space complexity: O(m)

    // Add the original index of each score to the array
    // Where the score is the key
    int m = *max_element(score.begin(), score.end());  // O(n)
    vector<int> scoreToIndex(m + 1, 0); // space O(n)
    for(int i = 0; i < n; i++) scoreToIndex[score[i]] = i + 1; // O(n)

    const vector<string> MEDALS = {"Gold Medal", "Silver Medal", "Bronze Medal"};

    vector<string> rank(n);  
    int place = 1;
    for(int i = m; i >= 0; i--){  // O(m) where m is the maximum score 
        if(scoreToIndex[i] != 0){
            int originalIndex = scoreToIndex[i] - 1;
            if(place < 4) rank[originalIndex] = MEDALS[place - 1];
            else rank[originalIndex] = to_string(place);
            place++;
        }
    }

    return rank;
}