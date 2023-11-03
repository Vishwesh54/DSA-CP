#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int minutes=0, fresh=0;

    queue<pair<int, int>> rotten;
    int dx[]={0,0,1,-1},
        dy[]={1,-1,0,0};
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2) rotten.push({i,j});
            if(grid[i][j]==1) fresh++;
        }
    }

    while(!rotten.empty()){
        int k=rotten.size();
        // Since oranges can be rotten simultaneously we need to apply bfs for all of them at once
        while(k--){
            int x=rotten.front().first , y=rotten.front().second;
            rotten.pop();
            for(int i=0 ;i<4;i++){
                int nx=x+dx[i] ,ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n &&grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    rotten.push({nx,ny});
                    fresh--;
                }   
            }
        }
        //After this while loop if it is empty => we have travesred all rotten oranges and rotted its neighbors
        //If not still we need to traverse and explore remaining rotted oranges 
        if(!rotten.empty()) minutes++;
    }

    return fresh==0 ? minutes : -1;
}

int main(){
    vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
    int rotting = orangesRotting(v);
    cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
}