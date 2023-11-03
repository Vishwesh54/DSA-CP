#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool dfs(int node , vector<int> adj[] , vector<int> &vis){
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

bool canFinish(int V, vector<vector<int>>& prerequisites) {
    vector<int> adj[V];
    for(auto x: prerequisites){
        adj[x[1]].push_back(x[0]);
    }

    vector<int>vis(V,0);
    int cnt=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis);
        }
    }
    for(int i=0;i<V;i++){
        if(vis[i]!=2)
            cnt++;
    }
    return cnt == V;
}

int main(){
	int N = 4;
	int M = 3;
	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

    cout<<(canFinish(N,prerequisites)?"YES":"NO");
	return 0;
}