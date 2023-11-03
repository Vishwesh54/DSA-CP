#include<bits/stdc++.h>
using namespace std;

/*
class DisjointSet{
private:
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
*/

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

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int findCircleNum(vector<vector<int>>& adj) {
    int n = adj.size();
    DisjointSet ds(n);
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]){       // If there is an edge between i & j
                ds.Union_By_Size(i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(ds.find(i)==i) cnt++;
    }
    
    return cnt;
}

int main(){
    vector<vector<int>>v={{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(v);
    return 0;
}   