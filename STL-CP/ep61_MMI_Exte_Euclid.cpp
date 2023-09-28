#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
#define mod int(1e9+7)
#define ll long long int 
using namespace std;

int BinaryExpo_Iter(int a, int b ,int m){
    int ans = 1;
    while(b){
        if(b&1) {
            ans = (ans * 1LL* a )%m;
        }
        a = (a*1LL*a)%m;
        b>>=1;
    } 
    return ans ;
}

int extended_euclid(int a, int b, int &x, int &y) {  //Returns the gcd of a,b
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int ans = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return ans;
}

int main(){
    gap
    cout<<"Enter a number : ";
    int n;
    cin>>n;
    cout<<"The inverse of "<<n<<" wrt to mod is : "<<BinaryExpo_Iter(n,mod-2,mod); gap
    
    int x,y;
    cout<<"Enter two numbers : ";
    int a,b;
    cin>>a>>b;
    int ans = extended_euclid(a,b,x,y);
    cout<<"The values of (x,y) are : "<<"("<<x<<","<<y<<")"; gap
    return 0;
}