#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    vector<int> adj[N];
    for(int i=0;i<M;i++){
        int u=edges[i][0] , v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N,1e7);
    dist[src]=0;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(int it:adj[node]){
            if(dist[node]+1 <dist[it]){
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }

    for(int i=0;i<N;i++){
        if(dist[i]==1e7)
            dist[i]=-1;
    }
    return dist;
}

int main(){
    int N=9, M=10;
    vector<vector<int>> edges= {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    vector<int> ans = shortestPath(edges,N,M,0);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    return 0;
}