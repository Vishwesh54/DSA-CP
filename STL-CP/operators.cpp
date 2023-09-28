#include<bits/stdc++.h>
#define gap cout<<endl;
using namespace std;

int main(){
    int a=3 ,b=4;
    cout<<(a<<3)<<endl;
    cout<<(a>>2)<<endl;
    cout<<~a<<endl;
    // cout<<a+++b<<endl;
    // cout<<a+++ ++b<<endl;
    int incr = (a<b) || (b++);   //2nd statement wont be executed
    cout<<incr<<" "<<b<<endl;

    int c=(3,5,8);
    int d;
    d=3 ,5 ,7;
    int e;
    e=(4,5,9);
    cout<<c<<" "<<d<<" "<<e; gap

    int i=10;
    int j= ++i + i++; 
    cout<<j; gap

    cout<<"Playing with left and right shift operators "; gap
    cout<<1ll; gap
    int hm = 1<<31 ;
    // cout<<(1<<31) -2; gap  //It is wrong since 1<<31 is INT_MIN so upon doing -1 it will overflow 
    cout<<(1<<31); gap // But this is correct since it is the value **INT_MIN** 
    cout<<(1LL<<31); gap 
    cout<<(1U<<31); gap 
    cout<<(1<<0); gap
    cout<<(0<<4); gap
    cout<<"Maximum value of unsigned int "<<(1LL<<32)-1;gap
    cout<<"Checking for maximum long long bits";gap
    cout<<(1LL<<63) <<" "<<LLONG_MIN; gap
    cout<<(1ULL<<63)-1 + (1ULL<<63) ;gap //maximum value of unsigned long long int
    // cout<<(1ULL<<64); gap // Not possible after 63

    /*Compute the smallest power of 2 that is not smaller than x
    (greater than or equal to x) */
    int x = 8;
    cout<<(1<<(32-__builtin_clzll(x-1)));
    return 0;
}