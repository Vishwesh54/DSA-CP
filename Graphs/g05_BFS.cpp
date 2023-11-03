#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

//O based indexing , starting node is 0
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int>ans;
    queue<int>q;
    vector<bool>visited(V,0);
    q.push(0) ,visited[0]=1;
    // int cnt=0; //To check how many times while loop runs
    while(!q.empty()){
        // cnt++;
        int node=q.front();
        visited[node]=1;
        q.pop();
        ans.push_back(node);
        for(auto x:adj[node]){
            if(!visited[x]){
                q.push(x);
            }
        }
    }
    // ans.push_back(cnt);
    return ans;
}

int main(){
    vector<int>adj[5]={{0,1},{0,2},{0,3},{2,4}};
    auto it=bfsOfGraph(5 , adj);
    for(int i:it) cout<<i<<" ";
    return 0;
}