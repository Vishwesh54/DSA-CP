#include <bits/stdc++.h>
using namespace std;

class DisjointSet{      
public:
    vector<int>parent,size;
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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0 , maxcol=0;    // Getting the maximum (x,y) coordinate

        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }

        DisjointSet ds(maxrow+1+maxcol+1);  // Since we need index for both of them

        for(auto it:stones){
            int row=it[0] , col=it[1] + 1 + maxrow;
            ds.Union_By_Size(row,col);
        }

        int connected=0;
        for(int i=0;i<ds.parent.size();i++){
            if(ds.find(i)==i && ds.size[i]>1)  // A single stome will have two nodes 
                connected++;
        }
        return n-connected;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> stones = {
        {0, 0}, {0, 2},
        {1, 3}, {3, 1},
        {3, 2}, {4, 3}
    };

    Solution obj;
    int ans = obj.removeStones(stones);
    cout << "The maximum number of stones we can remove is: " << ans << endl;
    return 0;
}