#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void dfs(int node ,vector<pair<int,int>> adj[] ,vector<bool> &vis ,stack<int> &st){
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i.first])
            dfs(i.first,adj,vis,st);
    }
    st.emplace(node);
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    vector<pair<int,int>>adj[N];
    for(int i=0;i<M;i++){
        int u = edges[i][0] , v=edges[i][1] , wt=edges[i][2];
        adj[u].push_back({v,wt});
    }

    vector<bool> vis(N,0);
    stack<int> st;

    for(int i=0 ;i<N;i++){
        if(!vis[i])
            dfs(i,adj,vis,st);
    }

    vector<int>distance(N,1e7);
    distance[0]=0;

    while(!st.empty()){
        int node=st.top();
        st.pop();

        for(auto it:adj[node]){
            int v=it.first , wt=it.second;
            if(distance[node]+wt < distance[v])
                distance[v] = wt + distance[node];
        }
    }

    for(int &i:distance)
    if(i==1e7)
        i=-1;

    return distance;
}

int main(){
    int N = 6, M = 7;
  
    vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    vector < int > ans = shortestPath(N, M, edges);
    
    for (int i = 0; i < ans.size(); i++) 
      cout << ans[i] << " ";
    
    return 0;
}