#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int>parent,size;

public:
    DisjointSet(int n){     //1 based indexing (Works for 0 based indexing as well)
        size.resize(n+1,1);     // Initially size of each component is 1
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

    void Union_By_Size(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY)  return ;  //If they are equal then they belong to same component so no need to union

        if(size[rootX] < size[rootY]){
            parent[rootX] = rootY;
            size[rootY] += size[rootX];  //We add the size of the attached component 
        }
        else{                       // Both cases can be handeled together as we know the size getting  
            parent[rootY] = rootX;  // attached 
            size[rootX] += size[rootY];
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
    ds.Union_By_Size(1, 2);         
    ds.Union_By_Size(2, 3);         
    ds.Union_By_Size(4, 5);         
    ds.Union_By_Size(6, 7);         
    ds.Union_By_Size(5, 6);         

    cout<<boolalpha;
    cout<<ds.connected(4,5)<<endl;   
    cout<<ds.connected(1,4)<<endl;
    cout<<ds.connected(7,3)<<endl;

    ds.Union_By_Size(3,7);
    cout<<ds.connected(7,3)<<endl;
    return 0;
}