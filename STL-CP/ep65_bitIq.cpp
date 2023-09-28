// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/
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
    ic(c)
    int bt_count= int(log2(c))+1;
    int a=0, b=0;
    vector<int> set_bits;
    for(int i=0 ;i<bt_count ;i++){
        if( c&(1<<i)){
            set_bits.pb(i);
        }
        else{
            a |= (1<<i);
            b |= (1<<i);
        }
    }

    ll ans=-1;
    int sz = 1<<set_bits.size();
    for(int mask=0; mask<sz ;mask++){
        int a_copy=a ,b_copy=b;
        for(int j=0 ;j<set_bits.size() ;j++){
            if(mask & (1<<j)){
                a_copy |= (1<<set_bits[j]);
            }
            else{
                b_copy |= (1<<set_bits[j]);
            }
        }
        ans =max(ans,a_copy*1LL*b_copy );
    }
    cout<<ans;
}

int main(){
    io;
    solve();
    cout<<endl;
    
    return 0;
}