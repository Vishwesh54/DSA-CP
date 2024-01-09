#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

void solve(int col,vector<string> &board, vector<vector<string>> &ans ,vector<bool>&lr, vector<bool>&ld,vector<bool>&ud,int n){
    if(col== n){
        ans.push_back(board);
    }
    else{
        for(int row=0 ; row<n ;row++){
            if(lr[row]==0 && ld[row+col]==0 && ud[n-1+col-row]==0){
                board[row][col]='Q';
                lr[row] = ld[row+col] = ud[n-1+col-row] = 1;
                solve(col+1,board,ans,lr,ld,ud,n);
                board[row][col]='.';
                lr[row] = ld[row+col] = ud[n-1+col-row] = 0;
            }
        }
    }
}

vector<vector<string>>solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>board(n,string(n,'.'));
    vector<bool>leftrow(n,0) ,upperdiagonal(2*n-1),lowerdiagonal(2*n-1);
    solve(0,board,ans,leftrow,lowerdiagonal,upperdiagonal,n);
    return ans;    
}

int main(){
    auto it=solveNQueens(4);
    for(auto i:it){
        for(auto j:i){
            cout<<j<<" "<<endl;
        }
        cout<<endl;
    }
    return 0;
}