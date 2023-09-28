#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool> prime(n+1,1);
    prime[0]=prime[1]=false;
    // for(int i=2 ;i<=n;i++){
    //     if(prime[i] == true){
    //         for(int j=2*i ;j<=n;j+=i)
    //             prime[j]=false;
    //     }
    // }

    for(int i=2 ; i*i<=n ;i++){
        if(prime[i]){
            for(int j=i*i ; j<=n ;j+=i){
                prime[j]=false;
            }
        }
    }
    cout<<"The following are the prime numbers upto "<<n<<endl;
    for(int i=0 ;i<=n;i++){
        if(prime[i]) cout<<i<<" ";
    }
    return 0;
}