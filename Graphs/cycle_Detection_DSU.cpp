#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>parent,rank;
public:
    DisjointSet(int n){     //1 based indexing (Works for 0 based indexing as well)
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0 ; i<=n ; i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);  //Path compression 
    }

    void Union_by_Rank(int x, int y) {
        int rootX = find(x) , rootY = find(y);

        if (rootX != rootY)   //If they are equal then they belong to same component so no need to union
        {
            if (rank[rootX] > rank[rootY]) {   //Smaller gets attached to larger one
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else {                      //In case they are equal attach it to anyone 
                parent[rootY] = rootX;
                rank[rootX] ++;        // since rootY is getting attached to rootX which increases rank of rootX
            }
        }
    }
};

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
        DisjointSet ds(V);
        for(int i=0 ; i<V ; i++){                   // We have to iterate over the edges
            for(int j=0 ; j<adj[i].size() ; j++){
                if(i < adj[i][j]){          // What a conditon to avoid same edges twice 
                    int u = i , v = adj[i][j];
                    if(ds.find(u) == ds.find(v))
                        return true;
                    ds.Union_by_Rank(u,v);
                }
            }
        }
        return false;
	}
};

void addEdge(int u , int v , vector<int> adj[]){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V = 6;
    vector<int>adj[V];

    addEdge(0, 1, adj) ,addEdge(0, 2, adj) ,addEdge(1, 3, adj);
    addEdge(3, 4, adj) ,addEdge(2, 3, adj) ,addEdge(4, 5, adj); 

/*
      1---3
     /   /|
    0   / |  5
     \ /  | /
      2   4
*/
    Solution S;
    cout<<S.detectCycle(V,adj);

    return 0;
}