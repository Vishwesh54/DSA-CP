#include<bits/stdc++.h>
#define gap cout<<endl;
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    vector<int> dist(V,1e7);
    dist[S]=0;
    pq.push({S,0});

    while(!pq.empty()){
        auto [node , dis] = pq.top();
        pq.pop();

        for(auto it:adj[node]){
            int adjnode = it[0] ,wt=it[1];
            if(wt+dis<dist[adjnode]){
                dist[adjnode] = wt + dis;
                pq.push({adjnode , dist[adjnode]}); 
            }
        }
    }
    return dist;
}

int main(){
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> res = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++){
        cout << res[i] << " ";
    }
    return 0;
}