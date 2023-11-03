#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

void bfs(int i,int j ,vector<vector<int>> &mat ,int m, int n){
    queue<pair<int,int>>q;
    q.push({i,j});
    mat[i][j]=0;

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,-1,1};

    while(!q.empty()){
        auto [row,col] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=row+dx[i];
            int ny=col+dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n && mat[nx][ny]==1){
                mat[nx][ny]=0;
                q.push({nx,ny});
            }
        }    
    }
}

int numberOfEnclaves(vector<vector<int>> &mat) {
    int m=mat.size() , n=mat[0].size();    
    for(int i=0 ; i<n ;i++){
        if(mat[0][i]==1)      //1st row
            bfs(0,i,mat,m,n);
        if(mat[m-1][i]==1)    //Last row
            bfs(m-1,i,mat,m,n);
    }

    for(int i=0 ; i<m ;i++){
        if(mat[i][0]==1)      //1st column
            bfs(i,0,mat,m,n);
        if(mat[i][n-1]==1)    //Last column
            bfs(i,n-1,mat,m,n);
    }

    int ans=0;
    for(int i=0 ;i<m ;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1)
                ans++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> 
    v={{0, 0, 0, 0},
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}};

    cout<<numberOfEnclaves(v);
    return 0;
}