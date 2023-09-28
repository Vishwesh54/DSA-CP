#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>> ans;
    int N = (1<<n);
    for(int i=0 ;i <N ;i++){
        vector<int>temp;
        for(int j=0 ;j<n;j++){
            if (i &(1<<j)) temp.push_back(v[j]);
        }
        ans .push_back(temp);
    }
    for(auto vec:ans){
        for(auto i:vec){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}