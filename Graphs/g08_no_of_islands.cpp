#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

int counter=0; //To analyse TC
void bfs(int row,int col ,vector<vector<char>> &grid ,int n ,int m){
    grid[row][col]='0';
    queue<pair<int,int>>q;
    q.push({row,col});

    while(!q.empty()){
        // counter++;
        row=q.front().first;
        col=q.front().second;
        q.pop();

        for(int x=-1 ; x<=1 ;x++){
            for(int y=-1 ; y<=1 ;y++){
                int neigx= x+row ,neigy= y+col;
                if(neigx>=0 && neigx<n && neigy>=0 && neigy<m && grid[neigx][neigy]=='1'){
                    q.push({neigx,neigy});
                    grid[neigx][neigy]='0';
                }
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n=grid.size() , m=grid[0].size() , cnt=0;
    for(int i=0 ; i<n;i++){
        for(int j=0;j<m;j++){
            // counter++;
            if(grid[i][j]=='1'){
                cnt++,bfs(i,j,grid,n,m);
            }
        }
    }    
    return cnt;
}


int main(){
    vector<vector<char>> grid(5,vector<char>(5,'1'));   //All are 1
    auto it=numIslands(grid);
    // cout<<counter<< " "<<it;
    cout<<it;
    return 0;
}