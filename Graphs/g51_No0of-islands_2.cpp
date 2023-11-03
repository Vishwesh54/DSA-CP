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
                rank[rootX]++;        // since rootY is getting attached to rootX which increases rank of rootX
            }
        }
    }
};

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    vector<vector<bool>> vis (n,vector<bool>(m,0));
    vector<int>ans;
    DisjointSet ds(n*m);
    int islands_cnt=0;
    
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    for(auto it:operators){
        int x = it[0] , y = it[1];
        
        if(vis[x][y]){      // Means it is already converted to 1 so no need to go further 
            ans.push_back(islands_cnt);
            continue;
        }

        vis[x][y]=1; //Conver it to island
        islands_cnt++;      // New island formed

        int node = x*m+y;
        for(int i=0;i<4;i++){               //Connecting adjacent nodes
            int nx=x+dx[i] , ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]){  //Careful we can connect only if its 1 not 0
                int adjnode = nx*m+ny;

                if(ds.find(node)!=ds.find(adjnode)){
                    ds.Union_by_Rank(node,adjnode);
                    islands_cnt--;
                }
            }
        }
        ans.push_back(islands_cnt);
    }
    return ans;
}

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

    vector<int> ans  = numOfIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }

    return 0;
}