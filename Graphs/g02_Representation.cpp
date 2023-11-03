#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

int main(){
    int n=5 ,m=6;
    vector<pair<int,int>>vp{{1,2},{1,3},{2,4},{3,4},{3,5},{4,5}};

    // Adjacency Matrix
    int adjm[n+1][n+1]={0};
    for(int i=0;i<m;i++){
        int u=vp[i].first , v=vp[i].second;
        adjm[u][v]=1;
        adjm[v][u]=1;
    }
    /*    
    for(int i=1 ; i<=n ;i++){
        for(int j=1 ; j<=n ;j++){
            cout<<adjm[i][j]<<" ";
        }
        gap
    }
    */

    // Adjacency List
    vector<int>adjl[n+1];
    for(int i=0;i<m;i++){
        int u=vp[i].first , v=vp[i].second;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    
    for(int i=1 ;i<=n;i++){
        cout<<i<<" --> ";
        for(int j:adjl[i])
            cout<<j<<" ";
        gap
    }

    return 0;
}