#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    queue<int>q;
    q.push(node);
    vis[node]=true;

    while(!q.empty()){
        node=q.front();
        q.pop();
        for(int i=0 ;i<adj.size();i++){
            if(adj[node][i] && !vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& adj) {
    int n = adj.size();
    int cnt = 0;
    vector<bool> vis(n);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            bfs(i, adj, vis);
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>>v={{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(v);
    return 0;
}   