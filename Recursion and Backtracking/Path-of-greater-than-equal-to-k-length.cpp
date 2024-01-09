#include<bits/stdc++.h>
using namespace std;

bool solve(vector<pair<int,int>> adj[] , int k ,vector<bool> &vis, int node ,int pathlen){
    if(pathlen >= k)
        return true;
            
    vis[node]=true;
    for(auto it:adj[node]){
        int v = it.first , wt=it.second;
        if(!vis[v]){
            if(solve(adj,k,vis,v,pathlen+wt))
                return true;
        }
    }
    vis[node] = false;  //Backtrack remove the node from our path 
    return false;
}

bool pathMoreThanK(int V, int E, int k, int *a) { 
    vector<pair<int,int>> adj[V];
    vector<bool>vis(V,0);   //We are using this array to keep a track of the nodes included in our path 

    for(int i=0;i<3*E;i+=3){
        int u=a[i] , v=a[i+1] , wt=a[i+2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    return solve(adj,k,vis,0,0);
} 

int main(){
    int A[] = {0, 1, 4, 0, 7, 8, 1, 2, 8, 1, 7, 11, 2, 3, 7, 2, 5, 4, 2, 8, 2, 3, 4, 9, 3, 5, 14, 4, 5, 10, 5, 6, 2, 6, 7, 1, 6, 8, 6, 7, 8, 7};
    int V=9 , E=14 , K=60;
    cout<<pathMoreThanK(V,E,K,A);     // 0 -> 7 -> 1 -> 2 -> 8 -> 6 -> 5 -> 3 -> 4  this path has a distance of 60
    return 0;
}