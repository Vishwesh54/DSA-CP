#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countPaths(int n, vector<vector<int>> &roads){
        const int mod = 1e9+7;
        typedef long long int ll;
        
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<ll>dist(n,1e12) ,ways(n,0);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>> ,greater<pair<ll,ll>>>q;
        dist[0]=0 , ways[0]=1;
        q.push({0,0});
        
        while(!q.empty()){
            auto [dis,u] = q.top();
            q.pop();

            for(auto it:adj[u]){
                auto [v,wt]=it;
                if(wt+dis<dist[v]){
                    dist[v]=dis+wt;
                    q.push({wt+dis,v});
                    ways[v] = ways[u];
                }
                else if(wt+dis == dist[v]){
                    ways[v] = (ways[v]+ways[u])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

int main(){
    int n = 7;
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;
    int ans = obj.countPaths(n, edges);
    cout << ans;

    return 0;
}