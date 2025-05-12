#include<bits/stdc++.h>
using namespace std;

bool canPartitionGrid(vector<vector<int>>& grid); // Leetcode-3548

int main(){

    // not able to solve the question ☹️☹️☹️
    
    return 0;
}

// bool canPartitionGrid(vector<vector<int>>& grid){
//     int row = grid.size();
//     int col = grid[0].size();  

//     vector<long> row_computation(row, 0);  
//     for(int i = 0; i < row; i++){  
//         long sum = 0;
//         for(int j = 0; j < col; j++) sum += grid[i][j];
//         row_computation[i] = sum;
//     }
//     if(check1(row_computation, grid)) return true;  

//     vector<long> col_computation(col, 0);
//     for(int j = 0; j < col; j++){     
//         long sum = 0;
//         for(int i = 0; i < row; i++) sum += grid[i][j];
//         col_computation[j] = sum;
//     }
//     if(check2(col_computation, grid)) return true;  

//     return false;
// }

// bool check1(vector<long> &arr, vector<vector<int>> &grid){  
//     int n = arr.size();
//     if(n == 1) return false;

//     vector<long> prefix(n, 0);  
//     prefix[0] = arr[0];
//     for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + arr[i];

//     vector<long> sufix(n, 0);  
//     sufix[n-1] = arr[n-1];
//     for(int i = n-2; i >= 0; i--) sufix[i] = sufix[i+1] + arr[i];

//     for(int i = 0; i < n-1; i++){
//         long pre = prefix[i], suf = sufix[i+1];
//         if(pre == suf) return true;

//         long diff = abs(pre - suf);
//         if(pre > suf && search1(diff, i, grid)) return true;
//         if(suf > pre && search1(diff, i+1, grid)) return true;
//     }

//     return false;
// }

// bool check2(vector<long> &arr, vector<vector<int>> &grid){  
//     int n = arr.size();
//     if(n == 1) return false;

//     vector<long> prefix(n, 0);  
//     prefix[0] = arr[0];
//     for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + arr[i];

//     vector<long> sufix(n, 0);  
//     sufix[n-1] = arr[n-1];
//     for(int i = n-2; i >= 0; i--) sufix[i] = sufix[i+1] + arr[i];

//     for(int i = 0; i < n-1; i++){
//         long pre = prefix[i], suf = sufix[i+1];
//         if(pre == suf) return true;

//         long diff = abs(pre - suf);
//         if(pre > suf && search2(diff, i, grid)) return true;
//         if(suf > pre && search2(diff, i+1, grid)) return true; 
//     }

//     return false;
// }

// bool search1(int ele, int i, vector<vector<int>> &grid){
//     int row = grid.size();
//     int col = grid[0].size();

//     for(int j = 0; j < col; j++){
//         if(grid[i][j] == ele){
//             if(i != 0 && i != row - 1) return true;
//             if((i == 0 || i == row - 1) && (j == 0 || j == col - 1)) return true;
//         }
//     }

//     return false;
// }

// bool search2(int ele, int j, vector<vector<int>> &grid){
//     int row = grid.size();
//     int col = grid[0].size();

//     for(int i = 0; i < row; i++){
//         if(grid[i][j] == ele){
//             if(j != 0 && j != col - 1) return true;
//             if((j == 0 || j == col - 1) && (i == 0 || i == row - 1)) return true;
//         }
//     }
   
//     return false;
// }




bool canPartitionGrid(vector<vector<int>>& grid){
    int row = grid.size(), col = grid[0].size();

    vector<long> row_sum(row, 0);
    vector<long> col_sum(col, 0);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
        }
    }
        
    for(int i = 0; i < row - 1; ++i){  // Check horizontal cuts
        long top_sum = accumulate(row_sum.begin(), row_sum.begin() + i + 1, 0L);
        long bottom_sum = accumulate(row_sum.begin() + i + 1, row_sum.end(), 0L);
        if(top_sum == bottom_sum) return true;
        long diff = abs(top_sum - bottom_sum);
        if(top_sum > bottom_sum){
            if(canRemove(grid, 0, i, diff, true)) return true;
        } 
        else{
            if (canRemove(grid, i + 1, row - 1, diff, true)) return true;
        }
    }
    
    for(int j = 0; j < col - 1; ++j){  // Check vertical cuts
        long left_sum = accumulate(col_sum.begin(), col_sum.begin() + j + 1, 0L);
        long right_sum = accumulate(col_sum.begin() + j + 1, col_sum.end(), 0L);
        if(left_sum == right_sum) return true;
        long diff = abs(left_sum - right_sum);
        if(left_sum > right_sum){
            if(canRemove(grid, 0, j, diff, false)) return true;
        } 
        else{
            if (canRemove(grid, j + 1, col - 1, diff, false)) return true;
        }
    }

    return false;
}

bool canRemove(vector<vector<int>>& grid, int start, int end, long diff, bool horizontal){
    int row = grid.size(), col = grid[0].size();

    if(horizontal){
        for(int i = start; i <= end; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == diff){
                    vector<vector<bool>> visited(row, vector<bool>(col, false));
                    visited[i][j] = true;
                    if(isConnected(grid, visited, start, end, true)) return true;
                }
            }
        }
    } 

    else{
        for(int j = start; j <= end; ++j){
            for(int i = 0; i < row; ++i){
                if(grid[i][j] == diff){
                    vector<vector<bool>> visited(row, vector<bool>(col, false));
                    visited[i][j] = true;
                    if (isConnected(grid, visited, start, end, false)) return true;
                }
            }
        }
    }

    return false;
}

bool isConnected(vector<vector<int>>& grid, vector<vector<bool>>& visited, int start, int end, bool horizontal){
    int row = grid.size(), col = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<bool>> seen(row, vector<bool>(col, false));
    
    for(int i = 0; i < row; ++i){  // Find the first unvisited cell in the section to start BFS
        for(int j = 0; j < col; ++j){
            if(visited[i][j]) continue;
            if((horizontal && i >= start && i <= end) || (!horizontal && j >= start && j <= end)){
                q.emplace(i, j);
                seen[i][j] = true;
                goto start_bfs;
            }
        }
    }

    return true; // If entire section was only the removed element

start_bfs:
    int cnt = 0, total = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(!visited[i][j] && ((horizontal && i >= start && i <= end) || (!horizontal && j >= start && j <= end))) total++;
        }
    }
                
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    while(!q.empty()){
        auto temp = q.front(); q.pop();
        int x = temp.first, y = temp.second;
        cnt++;

        for(int d = 0; d < 4; ++d){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx >= 0 && ny >= 0 && nx < row && ny < col && !seen[nx][ny] && !visited[nx][ny]){
                if((horizontal && nx >= start && nx <= end) || (!horizontal && ny >= start && ny <= end)){
                    seen[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    return cnt == total;
}


