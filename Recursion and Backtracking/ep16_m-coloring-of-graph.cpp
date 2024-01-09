#include <bits/stdc++.h>
using namespace std;

bool issafe(int node , bool graph[101][101] ,int m ,int n ,int color[] ,int col){
    for(int i=0 ; i<n ; i++){
        if(i!=node && graph[i][node] && color[i]==col)
            return false;
    }
    return true;
}

bool solve(int node , bool graph[101][101] ,int m ,int n ,int color[]){
    if(node==n) //Base case
        return true;
    
    //Try out all colors
    for(int i=1;i<=m;i++){
        if(issafe(node,graph,m,n,color,i)){
            color[node]=i;
            if(solve(node+1,graph,m,n,color))
                return true;
            else
                color[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n){
    int color[n]={0};
    if(solve(0,graph,m,n,color))
        return true;
    return false;
}

int main(){
    int N = 4;
    int m = 3;
    bool graph[101][101];
    memset(graph, false, sizeof graph);
    // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2) and its a undirected graph
    graph[0][1] = 1 , graph[1][0] = 1;
    graph[1][2] = 1 , graph[2][1] = 1;
    graph[2][3] = 1 , graph[3][2] = 1;
    graph[3][0] = 1 , graph[0][3] = 1;
    graph[0][2] = 1 , graph[2][0] = 1;

    cout << graphColoring(graph, m, N);
}