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
        int rootX = find(x);
        int rootY = find(y);

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

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &acc) {
        vector<vector<string>>ans;
        unordered_map<string,int>m;
        int n=acc.size();
        DisjointSet ds(n);

        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<acc[i].size() ; j++){
                if(!m.count(acc[i][j]))
                    m[acc[i][j]] = i;
                else
                    ds.Union_by_Rank(m[acc[i][j]],i);
            }
        }

        unordered_map<int,vector<string>>merge;

        for(auto it:m){
            string s = it.first ;
            int rootnode = ds.find(it.second);
            merge[rootnode].push_back(s);
        }

        for(auto &it:merge){
            vector<string>temp{acc[it.first][0]};
            sort(it.second.begin() , it.second.end());
            for(auto j:it.second){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


int main() {
    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);
    for (auto acc : ans) {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}