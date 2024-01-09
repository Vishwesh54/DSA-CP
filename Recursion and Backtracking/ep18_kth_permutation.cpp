#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

string getPermutation(int n, int k) {
    string ans="";
    int fact=1;
    vector<int>v;
    for(int i=1 ;i<n;i++){
        fact *= i;
        v.push_back(i);
    }
    v.push_back(n);
    k--;
    while(true){
        ans+= to_string(v[k/fact]);
        v.erase(v.begin()+k/fact);
        if(v.size()==0)
            break;
        k %= fact;
        fact /= v.size();
    }
    return ans;
}

int main(){
    string res=getPermutation(4,17);
    cout<<res;
    return 0;
}