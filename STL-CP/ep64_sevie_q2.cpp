// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/
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

const int N=2e6+10;
int hp[N];
vector<bool> canremove(N); 
vector<bool> hsh(N);


vector<int>factors(int x){
    vector<int>ans;
    while(x>1){
        int pf =hp[x];
        while(x%pf==0) x/=pf;
        ans.pb(pf);
    }
    return ans;
}


void solve(){
    rep(i,2,N){
        if(hp[i] ==0 ){
            for(int j=i ;j<N ;j+=i){
                hp[j]=i;
            }
        }
    }

    ic(n) ic(q)
    for0(n){
        ic(x)
        hsh[x]=1;
    }

    rep(i,2,N){
        if(hsh[i]){
            for(ll j=i ; j<N ;j*= i){
                canremove[j]=1;
            }
        }
    }

    while(q--){
        ic(x)
        vector<int>v=factors(x);
        bool ispossible=false;
        for0(Si(v)){
            rep(j,i,Si(v)){
                int product=v[i]*v[j];
                if(i==j && x%product !=0 ) continue;
                int toremove = x/product;
                if(canremove[toremove] || toremove==1){
                    ispossible=true;
                    break;
                }
            }
            if(ispossible) break; //to come out of this loop also
        }
        cout<<(ispossible?"YES":"NO")<<endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif
    io;
    solve();
    cout<<endl;
    
    return 0;
}