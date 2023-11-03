#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V,0) ,ans;
    for(int i=0;i<V;i++){
        for(int it:adj[i])
            indegree[it]++;
    }

    queue<int>q;
    for(int i=0;i<V;i++){
        if(!indegree[i]) 
            q.emplace(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.emplace_back(node);

        for(int i:adj[node]){
            indegree[i]--;
            if(!indegree[i])
                q.emplace(i);
        }
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