#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2025-09-01

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents);  // Leetcode-1792

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    return 0;
}

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents){
    int n = classes.size();
    vector<double> ratio(n, 0);            // Time complexity: O(n) + O(nlogn + mlogn)
    priority_queue<pair<double, int>> hp;  // space complexity: O(n)

    for(int i = 0; i < n; i++){  // O(nlogn)
        double current_ratio = (double)classes[i][0] / classes[i][1];
        double final_ratio = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
        ratio[i] = current_ratio;
        double  ratio_gain = final_ratio - current_ratio;
        hp.push({ratio_gain, i});
    }

    while(extraStudents--){  // O(mlogn) where extraStudent = m;
        auto temp = hp.top();
        hp.pop();

        int idx = temp.second;
        double ratio_gain = temp.first;
        ratio[idx] += ratio_gain;
        classes[idx][0]++;
        classes[idx][1]++;

        double new_current_ratio = ratio[idx];
        double new_final_ratio = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
        double new_ratio_gain = new_final_ratio - new_current_ratio;
        hp.push({new_ratio_gain, idx});
    }

    double total = 0;
    for(auto ele : ratio) total += ele;  // O(n)
    return total / n;
}