#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<vector<char>> &mat ,int m,int n){
    if(i<0 || j<0 || i>=m || j>=n || mat[i][j]!='O')    // !!! Kuch bhi ho 1st base case  !!!
        return;
    
    mat[i][j]='&';
    dfs(i,j+1,mat,m,n);
    dfs(i,j-1,mat,m,n);
    dfs(i+1,j,mat,m,n);
    dfs(i-1,j,mat,m,n);
}

void solve(vector<vector<char>>& mat) {
    int m=mat.size() , n=mat[0].size();
    for(int i=0 ; i<n ;i++){
        if(mat[0][i]=='O')      //1st row
            dfs(0,i,mat,m,n);
        if(mat[m-1][i]=='O')    //Last row
            dfs(m-1,i,mat,m,n);
    }

    for(int i=0 ; i<m ;i++){
        if(mat[i][0]=='O')      //1st column
            dfs(i,0,mat,m,n);
        if(mat[i][n-1]=='O')    //Last column
            dfs(i,n-1,mat,m,n);
    }

    for(int i=0 ;i<m ;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]=='&')
                mat[i][j]='O';
            else if(mat[i][j]=='O')
                mat[i][j]='X';
        }
    }
}

int main(){
    vector<vector<char>>grid = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}};
    solve(grid);

    for(auto i:grid){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}