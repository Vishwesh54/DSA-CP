#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool detect(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int, int>> q; // store <source node, parent node>
        q.push({src, -1});

        while (!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]){
                if (!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }

                // if adjacent node is visited and is not it's own parent node
                else if (parent != adjacentNode){
                    return true;        // yes it is a cycle
                }
            }
        }
        // there's no cycle
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]){
        int vis[V] = {0};
        for (int i = 0; i < V; i++){
            if (!vis[i]){
                if (detect(i, adj, vis))
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