#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
private:
    vector<int>parent,size;

public:
    DisjointSet(int n){     //1 based indexing (Works for 0 based indexing as well)
        size.resize(n+1,1);     // Initially size of each component is 1
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

    void Union_By_Size(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY)  return ;  //If they are equal then they belong to same component so no need to union

        if(size[rootX] < size[rootY]){
            parent[rootX] = rootY;
            size[rootY] += size[rootX];  //We add the size of the attached component 
        }
        else{                       // Both cases can be handeled together as we know the size getting  
            parent[rootY] = rootX;  // attached 
            size[rootX] += size[rootY];
        }
    }
};

class Solution{
public:
	int spanningTree(int V, vector<vector<int>> adj[]){
        vector<vector<int>>edges;
        DisjointSet ds(V);

        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                int v = j[0] , wt = j[1] ,u = i;
                edges.push_back({wt,u,v});
            }
        }

        sort(edges.begin(),edges.end());
        int mstwt=0;

        for(auto it:edges){
            int wt=it[0] , u=it[1] , v=it[2];
            if(ds.find(u) != ds.find(v)){
                mstwt += wt;
                ds.Union_By_Size(u,v);
            }
        }
        return mstwt;
	}
};

int main() {
	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}