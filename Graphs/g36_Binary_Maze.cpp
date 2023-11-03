#include <bits/stdc++.h>
using namespace std;

// class Solution{
// public:
//     int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination){
//         if (source==destination)
//             return 0;

//         int n=grid.size() ,m=grid[0].size();
//         vector<vector<int>> dist(n,vector<int>(m,1e5));
//         queue<pair<int,pair<int,int>>>q;
        
//         dist[source.first][source.second]=0;
//         q.push({0,source});

//         int dx[]={1,-1,0,0} ,dy[]={0,0,-1,1};

//         while(!q.empty()){
//             int dis=q.front().first;
//             int x=q.front().second.first;
//             int y=q.front().second.second;
//             q.pop();

//             for(int i=0;i<4;i++){
//                 int nx=x+dx[i] , ny=y+dy[i];
//                 if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] && dis+1 < dist[nx][ny]){
//                     dist[nx][ny]= dis+1;

//                     if(nx==destination.first && ny==destination.second)
//                         return dis+1;
//                     q.push({dist[nx][ny] ,{nx,ny}});
//                 }
//             }
//         }
//         return -1;
//     }
// };

// class Solution{
// public:
//     int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination){
//         if (source==destination)
//             return 0;

//         int n=grid.size() ,m=grid[0].size();
//         queue<pair<int,int>>q;
        
//         grid[source.first][source.second]=0;
//         q.push(source);

//         int dx[]={1,-1,0,0} ,dy[]={0,0,-1,1};

//         while(!q.empty()){
//             int x=q.front().first;
//             int y=q.front().second;
//             q.pop();

//             for(int i=0;i<4;i++){
//                 int nx=x+dx[i] , ny=y+dy[i];
//                 if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]){
//                     grid[nx][ny] = grid[x][y] + 1;

//                     if(nx==destination.first && ny==destination.second)
//                         return grid[nx][ny];
//                     q.push({nx,ny});
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution{
private:
    bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y){
        return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) && mat[x][y] == 1 && !visited[x][y];
    }
    
    void dfs(vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, int j, int x, int y, int &min_dist, int dist){
    if (i == x && j == y){
        min_dist = min(dist, min_dist);
        return;
    }
  
    visited[i][j] = true;         // set (i, j) cell as visited
    if (isSafe(mat, visited, i + 1, j)) {
        dfs(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
    }
    if (isSafe(mat, visited, i, j + 1)) {
        dfs(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
    }
    if (isSafe(mat, visited, i - 1, j)) {
        dfs(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
    }
    if (isSafe(mat, visited, i, j - 1)) {
        dfs(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
    }

    visited[i][j] = false;        // backtrack: remove (i, j) from the visited matrix
}

public:
    int shortestPath(vector<vector<int>> &mat, pair<int, int> src, pair<int, int> dest){
        if (mat[src.first][src.second] == 0 || mat[dest.first][dest.second] == 0)
        return -1;

        int n = mat.size() ,m = mat[0].size();
        vector<vector<bool>> visited;
        visited.resize(n, vector<bool>(m));
    
        int dist = INT_MAX;
        dfs(mat, visited, src.first, src.second, dest.first, dest.second, dist, 0);
    
        if (dist != INT_MAX)
            return dist;
        return -1;
    }
};


//Leetcode
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0]==1)       // Base case
        return -1;
    
    int n=grid.size();
    if(n==1 && grid[0][0]==0)  // When a single elemetn is present 
        return 1;
        
    queue<pair<int,int>>q;
    
    grid[0][0]=1;
    q.push({0,0});

    int dx[]={0,1,1,1,0,-1,-1,-1} ,dy[]={1,1,0,-1,-1,-1,0,1};

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<8;i++){
            int nx=x+dx[i] , ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && !grid[nx][ny]){
                grid[nx][ny]= grid[x][y]+1;

                if(nx==n-1 && ny==n-1)
                    return grid[nx][ny];
                q.push({nx,ny});
            }
        }
    }
    return -1;
}


// Given a 2D binary matrix A(0-based index) of dimensions NxM. 
// Find the minimum number of steps required to reach from (0,0) to (X, Y).
// You can only move left, right, up and down, and only through cells that contain 1.
int shortestDistance(int n, int m, vector<vector<int>> a, int X, int Y) {
    if(a[0][0]==0 || a[X][Y]==0)
        return -1;
    
    queue<pair<int,int>>q;
    q.push({0,0});
    a[0][0]=2;
    int ans=0;

    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    while(!q.empty()){
        int lvl=q.size();
        while(lvl--){
            int x=q.front().first , y=q.front().second;
            q.pop();
            if(x==X && y==Y)
                return ans;
            for(int i=0;i<4;i++){
                int nx=x+dx[i] , ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]==1 ){
                    a[nx][ny]=2;  //Marking as visited
                    q.push({nx,ny});
                }
            }
        }
        ans++;
    }
    return -1;
}

int main(){
    pair<int, int> source{0,1}, destination{2,2};
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    cout<<obj.shortestPath(grid, source, destination);

    return 0;
}