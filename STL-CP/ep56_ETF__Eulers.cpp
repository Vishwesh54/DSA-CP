/*Question
http://www.spoj.com/problems/MAS/
http://www.spoj.com/problems/ZSUM/
https://www.codechef.com/problems/CHMOD
*/
#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
#define mod int(1e9+7)
#define ll long long int 
using namespace std;

// When value of b gets large

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

int main(){
    /*      32
          64
        50
    */
    cout<<BinaryExpo_Iter(50,BinaryExpo_Iter(64,32,mod-1),mod); gap

    /*
           d
          c
         b
        a
    */
    cout<<BinaryExpo_Iter(2,BinaryExpo_Iter(2,BinaryExpo_Iter(2,2,mod-2),mod-1),mod);
    return 0;
}