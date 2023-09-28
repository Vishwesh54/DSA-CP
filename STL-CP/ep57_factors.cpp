#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long ct=0 ,sum=0;
    for(long long i=1 ;i*i<=n ;i++){
        if(n%i==0){
            cout<<i<<" ";
            ct++;
            sum+=i;
            if(n/i!=i){
                cout<<n/i<<" ";
                ct++;
                sum+=n/i;
            }
        }
    }   gap
    // cout<<ct<<" "<<sum;
    return 0;
}