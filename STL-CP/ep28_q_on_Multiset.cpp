#include<bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ic(input) ll input; cin>>input;
#define fc(input) ld input; cin>>input;
#define sc(input) string input; cin >> input;
#define all(nums) nums.begin(),nums.end()
#define Si(nums) nums.size()
#define for0(n) for (ll i = 0; i < n; i++)
#define for1(n) for (ll i = 1; i <= n; i++)
#define rep(It,x,y) for(int It=x; It<y; It++) 
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define vll vector<ll>
#define vi vector <int>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
using namespace std;

void solve(){
    ic(n) ic(m)
    unordered_multiset<ll> ms ;
    for0(n){
        ic(x)
        ms.insert(x);
    }
    while(m--){
        ic(y)
        auto it = ms.find(y);
        cout<<(it != ms.end() ? "YES":"NO")<<endl;
        ms.insert(y);
    }
}

int main(){
    io;
    ic(t)
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}