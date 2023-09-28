#include<bits/stdc++.h>
using namespace std;

void func1(int_fast64_t n){
    if(n==0) return ;
    cout<<n<<" ";
    func1(n-1);
}

void func2(int_fast64_t n){
    if(n==0) return;
    func2(n-1);
    cout<<n<<" ";
}
int main(){
    func1(5);
    cout<<endl;
    func2(5);
    return 0;
}       