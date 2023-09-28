#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

int main(){
    int n;
    cin>>n;
    bool flag=true;
    for(int i=2; i*i<=n;i++){
        if(n%i==0){
            flag=false;
            break;
        }
    }   
    cout<<flag; gap
    for(int i=2 ; i*i<=n;i++){
        while(n%i==0){
            cout<<i<<" ";
            n/=i;
        }
    } // n will be reduced after this loop
    if(n>1) cout<<n;   // When n will not be 1 it will be a prime number
    
    return 0;
}