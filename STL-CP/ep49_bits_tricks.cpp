#include<bits/stdc++.h>
#define gap cout<<endl;
using namespace std;

void printBinary(int n){
    for(int i=10; i>=0 ;i--){
        cout<<((n>>i) & 1)<<" ";
    }
    gap
}

int main(){
    cout<<(5 & 1 ? "Odd number ": "Even number"); gap
    
    //To covert to uppercase using bit manipulation 

    for(char c='A' ; c<='E' ;c++){
        cout<<c<<" : ";
        printBinary(c);     // 5th bit is UNSET in capital letters
    }
    for(char c='a' ; c<='e' ;c++){
        cout<<c<<" : ";
        printBinary(c);     // 5th bit is SET in small letters
    }

    /*Upper to lower*/
    char c ='A';
    c = c|' ';     // c = c|(1<<5);
    cout<<c; gap

    /*Lower to upper*/
    char ch ='a';
    ch = ch & '_';  //ch = ch & (~(1<<5));
    cout<<ch; gap

    /*To unset LSB till ith bit*/
    int a = 59;
    printBinary(a);
    int i=3;
    int b = a & (~((1  <<(i+1)) -1 ));
    printBinary(b);

    /*Clear MSB till ith bit */
    int A = a &((1<<(i+1))-1);
    printBinary(A);
}