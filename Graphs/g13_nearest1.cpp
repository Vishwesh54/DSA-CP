#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    int n = grid.size(); 
	    int m = grid[0].size(); 
	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	    queue<pair<pair<int,int>, int>> q; 

	    for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            if(grid[i][j] == 1) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
	    
	    while(!q.empty()) {
	        int row = q.front().first.first; 
	        int col = q.front().first.second; 
	        int steps = q.front().second; 
	        q.pop(); 
	        dist[row][col] = steps; 

	        for(int i = 0;i<4;i++) {
	            int nrow = row + delrow[i]; 
	            int ncol = col + delcol[i]; 
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m  && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps+1});  
	            }
	        }
	    }
	    return dist; 
	}

    vector<vector<int>>nearest_in_place(vector<vector<int>>grid){
	    int row = grid.size();
	    int col = grid[0].size();
	    
	    queue<pair<int,int>> q;
	    
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(grid[i][j]==1) {
	                q.push({i,j});
	                grid[i][j]=0;
	            }
	            else grid[i][j]=-1;
	        }
	    }
	    
	    int dx[] = {0, 0, 1, -1};
	    int dy[] = {1, -1, 0 , 0};
	    
	    while(!q.empty()){
	        int a = q.front().first;
	        int b = q.front().second;
	        q.pop();
	        
	        for(int k=0;k<4;k++){
	            int na = a+dx[k];
	            int nb = b+dy[k];
	            
	            if(na>=0 && nb>=0 && na<row && nb<col && grid[na][nb]==-1){
	                q.push({na,nb});
	                grid[na][nb]=grid[a][b]+1;
	            }
	        }
	    }
	    return grid;
	}
};

int main(){
    vector<vector<int>>grid{{1,0,1},{1,1,0},{1,0,0}};
	Solution obj;
	vector<vector<int>> ans = obj.nearest_in_place(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}