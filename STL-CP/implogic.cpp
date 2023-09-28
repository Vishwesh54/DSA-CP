#include<bits/stdc++.h>
#define pb push_back
#define ic(input) ll input; cin>>input;
#define fc(input) ld input; cin>>input;
#define sc(input) string input; cin >> input;
#define all(nums) nums.begin(),nums.end()
#define rall(nums) nums.rbegin(),nums.rend()
#define Si(nums) nums.size()
#define for0(n) for (ll i = 0; i < n; i++)
#define rep(It,x,y) for(ll It=x; It<y; It++) 
#define ll long long int
#define ld long double
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
using namespace std;

void solve(){
    ic(n)   
    vll v(n);
    for0(n){
        cin>>v[i];
    }
    sort(all(v));
    vll b;
    for0(n){
        if(i==0 || v[i] != v[i-1])
            b.emplace_back(v[i]);
    }
    for0(n){
        if(i>0 && v[i] == v[i-1])
            b.emplace_back(v[i]);
    }
    for0(n) cout<<b[i]<<" ";

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif
    ic(t)
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}