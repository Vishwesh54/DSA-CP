#include<bits/stdc++.h>
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() ,ans = 0 ,cnt=0;
        DisjointSet ds(n*n);
        int dx[] = {0,1,0,-1} , dy[] = {1,0,-1,0};

        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){

                if(grid[x][y]==1){
                    cnt++;
                    int node = x*n + y;
                    for(int k=0;k<4;k++){
                        int nx = x + dx[k] , ny = y + dy[k] , adjnode = nx*n + ny;

                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1){
                            ds.Union_By_Size(node,adjnode);
                        }
                    }
                }
            }
        }

        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){

                if(grid[x][y]==0){
                    int temp=0;
                    unordered_set<int>s;
                    for(int i=0 ; i<4; i++){
                        int nx = x + dx[i] , ny = y+ dy[i] , node = nx*n + ny;
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1)
                            s.insert(ds.find(node));
                    }

                    for(int i:s){
                        temp+= ds.size[i];
                    }

                    ans=max(ans,temp+1);
                }
            }
        }
        return cnt==n*n ? cnt : ans;
    }
};
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, 
        {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0}, 
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}, 
        {0, 0, 1, 1, 1, 0}
    };

    Solution obj;
    int ans = obj.largestIsland(grid);
    cout << "The largest group of connected 1s is of size: " << ans ;
    return 0;
}

