// https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/
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

const int N=2e5+10;
int multiples_count[N] ,hsh[N];

void solve(){
    ic(n)
    for0(n){
        ic(x)
        hsh[x]++;
    }    
    for(int i=1 ;i<N ;i++){
        for(int j=i ;j<N;j+=i){
            multiples_count[i]+=hsh[j];
        }
    }
    ic(q)
    while(q--){
        ic(p) ic(q)
        ll lcm=(p*q)/__gcd(p,q);
        ll ans= multiples_count[p]+multiples_count[q];
        if(lcm<N) ans-=multiples_count[lcm];
        cout<<ans<<endl;
    }
}

int main(){
    io;
    solve();
    return 0;
}

// https://codeforces.com/contest/1850/problem/F ~similar question