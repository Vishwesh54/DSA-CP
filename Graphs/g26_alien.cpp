#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st){
    vis[node] = true;
    for(int i:adj[node]){
        if(!vis[i])
            dfs(i,adj,vis,st);
    }

    st.push(node);
}

string findOrder_dfs(string dict[], int N, int k){
    vector<int> adj[k];
    for(int i=0;i<N-1;i++){
        string s1=dict[i] ,s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        
        for(int j=0;j<len;j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }   
    string ans;
    stack<int> st;
    vector<bool> vis(k, 0);
    for (int i = 0; i < k; i++){
        if(!vis[i])
            dfs(i, adj, vis, st);
    }

    while (!st.empty()){
        ans.push_back('a' + st.top());
        st.pop();
    }

    return ans;
}


// <<<<<------------------------------------------->>>>//
// ----------------- BFS Kahns -----------------------//
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V,0) ,ans;
    for(int i=0;i<V;i++){
        for(int it:adj[i])
            indegree[it]++;
    }

    queue<int>q;
    for(int i=0;i<V;i++){
        if(!indegree[i]) 
            q.emplace(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.emplace_back(node);

        for(int i:adj[node]){
            indegree[i]--;
            if(!indegree[i])
                q.emplace(i);
        }
    }
    return ans;
}

string findOrder_bfs(string dict[], int N, int K) {
    vector<int>adj[K];

    for(int i=0;i<N-1;i++){
        string s1=dict[i] ,s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        
        for(int j=0;j<len;j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }    

    vector<int> topo =topoSort(K,adj);
    string res="";

    for(int i:topo) res+= char(i+'a');

    return res;
}

int main(){
    int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	string ans =findOrder_dfs(dict, N, K);

    cout<<ans;
	return 0;
}