#include<bits/stdc++.h>
using namespace std;

void solve(int x, int y,int X,int Y ,int &ans ,vector<vector<int>> &grid ,int pathlen ,vector<vector<int>> &vis ,int n ,int m){
    if(x==X && y==Y){
        ans=max(ans,pathlen);
        return;
    }

    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    for(int i=0;i<4;i++){
        int nx=x+dx[i] , ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
            vis[nx][ny]=1;
            solve(nx,ny,X,Y,ans,grid ,pathlen+1 ,vis ,n,m);
            vis[nx][ny]=0;
        }
    }
}

int longestPath(vector<vector<int>> grid, int x, int y, int X, int Y){
    if(grid[x][y]==0 || grid[X][Y]==0)
        return -1;

    int n=grid.size() , m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    vis[x][y]=1;

    int ans=-1;
    solve(x,y,X,Y,ans,grid,0,vis,n,m);
    return ans;
}

int main(){
    vector<vector<int>> matrix{
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,0,1,1,0,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
    cout<<longestPath(matrix,0,0,1,7);

    return 0;
}