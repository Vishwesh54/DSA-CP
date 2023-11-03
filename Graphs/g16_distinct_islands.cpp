#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col ,vector<vector<int>> &vis , vector<vector<int>> &grid ,vector<pair<int,int>> &temp ,int x0 ,int y0){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    temp.push_back({row-x0,col-y0});
    int n=grid.size() , m=grid[0].size();
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};

    while(!q.empty()){
        int x=q.front().first , y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x +dx[i] , ny = y +dy[i];
            if(nx>=0 && nx<n &&ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny]=1;
                temp.push_back({nx-x0,ny-y0});
            }
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n=grid.size() , m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]){
                vector<pair<int,int>>temp;
                bfs(i,j,vis,grid,temp,i,j);
                st.insert(temp);
            }
        }
    }
    return st.size();
}

int main(){
    vector<vector<int>> 
    v={{1, 1, 0, 1, 1},
       {1, 0, 0, 0, 0},
       {0, 0, 0, 0, 1},
       {1, 1, 0, 1, 1}};
    
    cout<<countDistinctIslands(v);
    return 0;
}