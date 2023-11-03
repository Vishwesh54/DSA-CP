#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
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

int main(){
    
//        1          4
//       / \        / \ 
//      2   3      5   6 
//                      \ 
//                       7

    DisjointSet ds(7);
    ds.Union_by_Rank(1, 2);         
    ds.Union_by_Rank(2, 3);         
    ds.Union_by_Rank(4, 5);         
    ds.Union_by_Rank(6, 7);         
    ds.Union_by_Rank(5, 6);         

    cout<<boolalpha;
    cout<<ds.connected(4,5)<<endl;   
    cout<<ds.connected(1,4)<<endl;
    cout<<ds.connected(7,3)<<endl;

    ds.Union_by_Rank(3,7);
    cout<<ds.connected(7,3)<<endl;
    return 0;
}