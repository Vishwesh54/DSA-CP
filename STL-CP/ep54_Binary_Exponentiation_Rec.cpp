#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
#define mod int(1e9+7)
#define ll long long int 
using namespace std;

int BinaryExpo_Recur(int a ,int n){
    if(n==0)        //When power is 0 ans is 1 obviously 
        return 1;
    long long int res = BinaryExpo_Recur(a,n/2);

    if(n&1){
        return a * res * res;
    }
    else{    
        return res * res;
    }
}

ll power(ll x, ll y) {ll ans = 1; while (y) {if (y & 1) ans = (ans * x) % mod; y >>= 1; x = (x * x) % mod;} return ans;} //Always Returns ans with mod

int BinaryExpo_Iter(int a, int n){
    int ans = 1;
    while(n){
        if(n&1) {
            ans = (ans * 1LL* a )%mod;
        }
        a = (a*1LL*a)%mod;
        n>>=1;
    } 
    return ans ;
}

int main(){
    cout<<BinaryExpo_Recur(2,16); gap
    cout<<BinaryExpo_Iter(2,16);gap
    cout<<power(2,65); gap
    cout<<BinaryExpo_Iter(2,65); gap
    return 0;
}