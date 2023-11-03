#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool dfs(int node, int parent, vector<int> adj[],  vector<bool> &vis){
        vis[node] = 1;
        for(int x:adj[node]){
            if(!vis[x]){
                if(dfs(x,node,adj,vis))
                    return true;
            }
            else if(x != parent)
                return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]){
        vector<bool> vis(V,0);
        for (int i = 0; i < V; i++){
            if (!vis[i]){
                if (dfs(i,-1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

int main(){
    vector<int> adj[5] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} ;
    Solution obj;
    bool ans = obj.isCycle(5, adj);
    cout<<(ans?"Cycle exists":"Cycle doesnt exists");
    return 0;
}