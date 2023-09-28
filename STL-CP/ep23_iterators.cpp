#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif

    vector<int> v = {2,3,5,6,7};
    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    vector<int>:: iterator it =v.begin();
    for(it ; it!=v.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;

    vector<pair<int , int>> v_p = {{1,2} , {3,4} ,{5,6}};
    vector<pair<int , int>> :: iterator i;
    for(i= v_p.begin() ; i != v_p.end() ;i++){
        cout<<i->first<<" "<<i->second;
        cout<<endl;
    }

    return 0;
}