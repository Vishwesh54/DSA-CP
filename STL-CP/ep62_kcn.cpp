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

const int N=1e5+2;
int fact[N];

int expo(int a, int b ,int m){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*1LL*a)%m;
        a=(a*1LL*a)%m;
        b>>=1;
    }
    return ans;
}

void solve(){
    ic(n) ic(k)
    fact[0]=1;
    for(int i=1 ; i<N ;i++){
        fact[i] = (fact[i-1]*1LL*i)%mod;
    }
    int ans = fact[k];
    ans = (ans *1LL* expo(fact[k-n],mod-2,mod))%mod;
    cout<<ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif
    io;
    ic(t)
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}