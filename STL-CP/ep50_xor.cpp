#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

void xortilln(int n){
    int ans=0;
    for(int i=1;i<=n ;i++){
        ans^=i;
    }
    cout<<n<<"-->"<<ans; gap
}

int main(){
    int a = 4 ,b =6;
    a = a^b;
    b = a^b;
    a = a^b;
    cout<<a<<" "<<b;gap

    int x; cin>>x;
    // for(int i=1 ;i<=x ;i++){
    //     xortilln(i);
    // }
    gap
    for(int i=1 ;i<=x ;i++){
        if(i%4 ==0) cout<<i<<"-->"<<i;
        else if (i%4 == 1) cout<<i<<"-->"<<1;
        else if(i%4 ==2) cout<<i<<"-->"<<i+1;
        else cout<<i<<"-->"<<0;
        cout<<"\n";
    }

    int arr[8] ={4,2,3,1,2,3,1,5};
    // for(int i=0;i<8;i++){
    //     int c =0;
    //     for(int j=0 ;j<8;j++){
    //         if(arr[i]==arr[j]) c++;
    //     }
    //     if(c==1) cout<<arr[i]<<" ";
    // }gap

    int Xor =0;
    for(int i=0;i<8;i++){
        Xor^=arr[i];
    }
    int cnt=0;
    while(Xor){
        if(Xor&1) break;
        cnt++;
        Xor>>=1;
    }
    int Xor1 =0 ,Xor0 =0;
    for(int i=0 ;i<8;i++){
        if(arr[i] & (1<<cnt)) Xor1^=arr[i];
        else Xor0^=arr[i];
    }
    cout<<Xor0<<" "<<Xor1;gap
    return 0;
}