#include<iostream>
using namespace std;

int increment_return(int n){
    n++;
    return n;
}

void increment(int n){
    n++;
}

int main(){
    int a;
    cout<<"Enter a number :";
    cin>>a;
    cout<<increment_return(a)<<endl;
    increment(a);

    cout<<a;


    return 0;
}