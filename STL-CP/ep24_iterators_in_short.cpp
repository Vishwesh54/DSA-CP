#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v {2,3,5,6,7};
    vector<int> :: iterator it;
    for(it = v.begin() ;it!= v.end() ;it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    for(int &i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<pair<int , int>> v_p = {{1,2} , {3,4} ,{5,6}};
    for(pair<int,int> &value:v_p){
        cout<<value.first<<" "<<value.second;
        cout<<endl;
    }

    for(auto &i : v_p){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}