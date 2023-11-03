#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool dfs(int node , vector<int> adj[] , int vis[]){
    vis[node]=2;
    for(int it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis))
                return true;
        }
        else if(vis[it]==2)
            return true;
    }

    vis[node]=1;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis))
                return true;
        }
    }
    return false;
}

int main(){
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
    cout<<isCyclic(V,adj);
    return 0;
}