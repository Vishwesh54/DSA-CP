#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void dfs(int node ,vector<int> &vis , vector<int>adj[] ,stack<int> &st){
    vis[node]=1;

    for(int it:adj[node]){
        if(!vis[it])
            dfs(it,vis,adj,st);
    }

    st.emplace(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V,0) ,ans;
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i])
            dfs(i,vis,adj,st);
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
    auto ans = topoSort(V,adj);
    for(int i:ans) cout<<i<< " ";
    return 0;
}