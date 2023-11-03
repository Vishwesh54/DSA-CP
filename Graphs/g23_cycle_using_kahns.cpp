#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isCyclic(int n ,vector<int> adj[]){
    vector<int>indegree(n,0);
    queue<int>q;

    for(int i=0;i<n;i++){
        for(int it:adj[i]){
            indegree[it]++;
        }
    }    

    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;

        for(int it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.emplace(it);
        }
    }               //Bhai if cnt==n means no cycle na therefore return flase
    return !(cnt==n);   // since we are checking for a cycle 
}


int main() {
	//V = 6;
	vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
	int V = 6;

	bool ans = isCyclic(V, adj);

    cout<<(ans?"Yes":"NO");

	return 0;
}