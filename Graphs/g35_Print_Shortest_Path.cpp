#include<bits/stdc++.h>
#define gap cout<<endl;
using namespace std;

class Solution {
   public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<int> dist(n+1,1e8) , parent(n+1) , path;
        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        pq.push({0,1});
        dist[1]=0;
        for(int i=1;i<=n;i++)   parent[i]=i;

        while(!pq.empty()){
            // auto [dis,node] = pq.top();
            int node = pq.top().second , dis=pq.top().first;
            pq.pop();

            for(auto it:adj[node]){
                // auto [adjnode , wt] = it;
                int adjnode=it.first , wt=it.second;
                if(wt+dis<dist[adjnode]){
                    dist[adjnode] = wt+dis;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode]=node;
                }
            }
        }

        if(dist[n]==1e8)
            return {-1};
        
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        reverse(path.begin(),path.end());

        return path;
    }
};

int main(){
    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, 
    {3, 5, 1}};
    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}