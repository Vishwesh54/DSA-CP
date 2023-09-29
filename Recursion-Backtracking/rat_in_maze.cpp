#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

void solve(int i ,int j ,int dirx[] ,int diry[] , vector<string> &ans , string s ,vector<vector<int>> &m ,int n ,vector<vector<int>> &vis){
    if(i==n-1 && j==n-1){
        ans.push_back(s);
        return;
    }

    string dir="DLRU";
    for(int ind=0 ; ind<4 ;ind++){
        int nexti=i+dirx[ind];
        int nextj=j+diry[ind];
        if(nexti>=0 && nextj>=0 && nexti<n &&nextj<n && (!vis[nexti][nextj]) && m[nexti][nextj]==1 ){
            vis[i][j]=1;
            solve(nexti,nextj,dirx,diry,ans,s+dir[ind],m,n,vis);
            vis[i][j]=0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    if(m[0][0]==0 || m[n-1][n-1]==0)
        return {{"-1"}};
    
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int> (n,0));
    int dirx[] = {1,0,0,-1} ,diry[] = {0,-1,1,0};
    solve(0,0,dirx,diry,ans,"",m ,n,visited);
    if(ans.empty())
        return {{"-1"}};
    return ans;
}

int main(){
    int N=4;
    vector<vector<int>> m
        {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}} ;
    
    // int visited[N][N] = {0} ;
    // int dirx[] = {1,0,0,-1} ,diry[] = {0,-1,1,0};
    vector<string> ans = findPath(m,N);

    for(auto i:ans){
        for(auto j:i){
            cout<<j;
        }
        cout<<endl;
    }

    return 0;
}