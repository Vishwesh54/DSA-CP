#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool dfs(int node, int V ,vector<int> adj[] ,vector<int> &color ,int colour){
    color[node]=colour;

    for(int it:adj[node]){
        if(color[it]==-1){
            if(dfs(it,V,adj,color ,!colour)==false)
                return false;
        }
        else if(color[it]==color[node])
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    vector<int>color(V,-1);
    for(int i=0;i<V;i++){       //For connected components
        if(color[i]==-1){
            if(dfs(i,V,adj,color,0) == false)
                return false;
        }
    }
    return true;
}


void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    // 8 edges and 8 vertices
    vector<int> adj[8];
    addEdge(adj,0,1);    
    addEdge(adj,1,2);    
    addEdge(adj,2,3);    
    addEdge(adj,3,4);    
    addEdge(adj,4,7);    
    addEdge(adj,4,5);    
    addEdge(adj,1,6);    
    addEdge(adj,5,6);    

    // addEdge(adj ,0, 2);
    // addEdge(adj ,0, 3);
    // addEdge(adj ,1, 3);
    // addEdge(adj ,2, 3);

    cout<<(isBipartite(8,adj)? "Bipartite":"Non Bipartite");
    return 0;
}