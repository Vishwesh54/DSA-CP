#include<bits/stdc++.h>
#define gap cout<<endl;
#define ll long long int
using namespace std;

void permuteallways(int i, int j ,int n ,int m ,vector<vector<int>> &ans,vector<vector<int>> &grid ,vector<int> &curr){
    if(i==n-1 && j==m-1){
        curr.push_back(grid[i][j]); //This done to add the last cell i.e the destination of the grid
        ans.push_back(curr);        //to the path because whenever this condition hits 
        curr.pop_back();            //you dont add the last cell. Then BACKTRACK
        return;
    }

    curr.push_back(grid[i][j]);
    if(i+1<n)   //If you can move right move right
        permuteallways(i+1,j,n,m,ans,grid,curr);  

    if(j+1<m)   //Similarly down
        permuteallways(i,j+1,n,m,ans,grid,curr);
    
    curr.pop_back();    //Backtrack
}

vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid){
    vector<vector<int>>ans;
    vector<int>curr;
    permuteallways(0,0,n,m,ans,grid,curr);
    return ans;
}

int main(){
    vector<vector<int>> grid{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto ans= findAllPossiblePaths(grid.size() ,grid[0].size() ,grid);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        gap
    }
    return 0;
}