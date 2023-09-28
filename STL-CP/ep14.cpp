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
#define fors(n) for (ll i = 0; i < n - 1; i++)
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
    ic(n) ic(q)
    int a[n+2] ,forward[n+2] , backward[n+2];
    forward[0] = backward[n+1] =0;
    for1(n) cin>>a[i];
    for1(n) forward[i]=__gcd(a[i],forward[i-1]);
    for(int i=n ; i>0 ;i--) backward[i] =__gcd(a[i],backward[i+1]);

    while(q--){
        ic(l) ic(r)
        cout<<__gcd(forward[l-1] ,backward[r+1])<<endl;
    }
}

int main(){
    io;
    ic(t)
    while(t--){
        solve();
    }
    return 0;
}