#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
#define ll long long int 
using namespace std;

// Incase a is large take modulo m at the beginning itself i.e a%=mod
// When a and m gets large (10^18 range)
#define mod (ll)(1e18+7)
ll BinaryMulti(ll a ,ll b);

/* TC: O(log^2(N)) */
ll BinaryExpo_Iter(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) {
            ans = BinaryMulti(ans,a);
        }
        a = BinaryMulti(a , a);
        b>>=1;
    } 
    return ans ;
}

/* TC: O(log(N)) */
ll BinaryMulti(ll a, ll b){
    ll ans = 0;
    while(b){
        if(b&1) {
            ans = (ans + a )%mod;
        }
        a = (a + a)%mod;
        b>>=1;
    } 
    return ans ;
}

/*Binary exponentiation on negative powers 
When x is in decimal */
double myPow(double x, long long n) {   // x^n
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        n = -1 * n;
        x = 1.0 / x;
    }

    double ans=1;
    while(n){
        if(n&1) ans=ans*x;
        x=x*x;
        n>>=1;
    }
    return ans;
}

int main(){
    cout<<BinaryExpo_Iter(1321443,57437);gap
    cout<<myPow(2,-2);gap
    cout<<setprecision(10)<<myPow(2.1,8);
    return 0;
}