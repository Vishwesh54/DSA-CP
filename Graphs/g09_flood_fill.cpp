#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int  curr=image[sr][sc] ,n=image.size(), m=image[0].size();

    /*If newColor is the same as color, after visiting a neighbour point of a starting point,
     The DFS function would visit the starting point again and this loop never stops.*/
    
    if(curr==newColor)
        return image;
    
    queue<pair<int,int>>q;
    q.push({sr,sc});
    image[sr][sc]=newColor;
    int x[] = {-1,0,1,0};
    int y[] = {0,1,0,-1};

    while (!q.empty()){
        int row=q.front().first , col=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int neigx = row + x[i];
            int neigy = col + y[i];
            if(neigx>=0 && neigx<n && neigy>=0 && neigy<m && image[neigx][neigy]==curr){
                q.push({neigx,neigy});
                image[neigx][neigy]=newColor;
            }
        }
    }
    return image;
}

int main(){
    vector<vector<int>> v{{1,1,1},{1,1,0},{1,0,1}};
    auto it=floodFill(v,1,1,2);
    for(auto i:it){
        for(int j:i){
            cout<<j<<" ";
        }
        gap
    }
    return 0;
}