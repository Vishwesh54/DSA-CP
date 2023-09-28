#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e7 +10;
int hsh[N];

int main(){
    io;    
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i< n; i++){
        cin>>a[i];
        hsh[a[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<hsh[x]<<endl;
    }   
    return 0;
}