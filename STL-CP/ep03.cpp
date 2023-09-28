#include<iostream>
#include<climits>
using namespace std;

int main(){
    cout<<8/5<<endl;   
    cout<<8.0/5<<endl;   
    cout<<'c' + 5.0<<endl;   

    int a=3/2.0;
    double d=3/2;      // 3/2.0 will give 1.5
    cout<<a<<" "<<d<<'\n';
    cout<<7*2/3<<" "<<7/2*3<<"\n";

    float ff=5;
    cout<<ff/2<<"\n";

    int b= 100000;              long int bb=100000;
    int c= 100000;              long int cc=100000;
    long long int e= b*c;       long ee=bb*1LL*cc;
    long long int f= b* 1LL *c;    //1LL means long long int 
    cout<<e<<endl;      //Gives wrong value
    cout<<f<<endl;
    cout<<ee<<endl;
    int l =1e+9;   
    int w =1e+9;
    cout<<"Area is :"<<l* 1LL *w<<endl;

    cout<<LONG_LONG_MAX;
    return 0;
}