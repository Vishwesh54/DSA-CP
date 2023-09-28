#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

// int Gcd(int a, int b){
//     if( b==0 )
//         return a;
//     return Gcd(b ,a%b);
// }

int Gcd(int a,int b){
    while(b!=0){
        int temp = a%b;
        a=b;
        b=temp;
    }
    return a;
}

int main(){
    cout<<Gcd(12,18);gap
    cout<<Gcd(18,12);gap
    cout<<Gcd(12,0);gap
    cout<<Gcd(0,0);gap
    cout<<Gcd(0,12);gap
    cout<<Gcd(61,96);gap
    cout<<(61*96)/Gcd(61,96);gap
    cout<<-7 %3;gap
    cout<<7%(-3); gap
    cout<<(-7)%(-3); gap
    
    return 0;
}