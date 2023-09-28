#include<bits/stdc++.h>
#define gap cout<<endl;
using namespace std;

void printBinary(int n){
    for(int i=31; i>=0 ;i--){
        cout<<((n>>i) & 1)<<" ";
    }
    gap
}
int main(){
    printBinary(9);
    int a =9;
    int i =1;
    //Check whether ith bit is set or not 
    if((a &(1<<i)) != 0){   // dont just write if(a &(1<<i) != 0 )  use () to ensure what must be calculate 1st
        cout<<"Set bit";
    }  
    else{
        cout<<"Unset bit"; 
    } gap

    // SET 1st bit
    a=a|(1<<i);
    printBinary(a);

    //Unset 1st bit
    int b=7;
    b = b&(~(1<<i));
    printBinary(b);

    //Toggle 1st bit
    b=b^(1<<1);
    printBinary(b);

    //To calculate set bits;
    int ct=0;
    for(int i=31 ;i>=0 ;i--){   
        if((b>>i) & 1) ct++;
    } 
    cout<<ct; gap

    cout<<__builtin_popcount(9);gap
    cout<<__builtin_popcountll((1ll<<54) -1 );gap
    
     
    return 0;
}