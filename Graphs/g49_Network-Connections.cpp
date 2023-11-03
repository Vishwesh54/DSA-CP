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
        int rootX = find(x);
        int rootY = find(y);

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
                rank[rootX]++;        // since rootY is getting attached to rootX which increases rank of rootX
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size()<n-1)
            return -1;

        DisjointSet ds(n);
        int connected = n ;  //Initially are single before union
        for(const auto &it : con){
            int u=it[0] , v=it[1];
            if(ds.find(u)!=ds.find(v)){
                connected--;        // Since we are merging two components 1 component gets reduced
                ds.Union_by_Rank(u,v);
            }
        } 
        return connected-1;     //For n components to be connected we need n-1 edges
    }
};

int main(){
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    int n=6;
    Solution s;
    cout<<s.makeConnected(n,edges);
    return 0;
}