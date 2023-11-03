#include <bits/stdc++.h>
using namespace std;

typedef struct mypair{
    int first,second,third;
}triplet;

class Solution{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int k){
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }        
        
        queue<triplet>q;
        vector<int> dist(n,1e9);
        dist[src]=0;
        q.push({0,0,0});

        while(!q.empty()){
            auto [stops,node,distance] = q.front();
            q.pop();

            if(stops > k || node==dst) continue;
            for(auto it:adj[node]){
                auto [adjnode,wt] = it;
                if(wt+distance<dist[adjnode] && stops<=k){
                    dist[adjnode]=wt+distance;
                    q.push({stops+1 , adjnode ,dist[adjnode]});
                }
            }
        }
        return dist[dst]==1e9 ? -1 : dist[dst];
    }
};

int main(){
    // Driver Code.
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};

    Solution obj;

    int ans = obj.CheapestFLight(n, flights, src, dst, K);
    cout << ans;

    return 0;
}