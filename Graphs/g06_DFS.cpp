#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

void dfs(int node ,vector<int>&ans, vector<bool> &vis ,vector<int>adj[]){
    vis[node]=1;
    ans.push_back(node);
    for(int x:adj[node]){
        if(!vis[x])
            dfs(x,ans,vis,adj);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int>ans;
    vector<bool>vis(V);
    dfs(0,ans,vis,adj); // Root Node 0 & 0-based indexing
    return ans;
}

int main(){
    vector<int>adj[5]={{0,1},{0,2},{0,3},{2,4}};
    auto it=dfsOfGraph(5 , adj);
    for(int i:it) cout<<i<<" ";
    return 0;
}