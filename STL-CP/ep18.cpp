#include<bits/stdc++.h>
using namespace std;

int sum(int a[] ,int n){ //function to return sum till nth index of an array
    if(n<0)
        return 0;
    return sum(a ,n-1) + a[n];
}

int digit_sum(int n){
    if (n==0) return 0;
    return digit_sum(n/10) +n%10;
}

int main(){
    int n; cout<<"Enter the size of the array : "; cin>>n;
    int *a= new int[n];
    cout<<"Enter the elements : ";
    for(int i=0 ; i< n;i++){
        cin>>a[i];
    }
    cout<<sum(a ,n-1)<<endl;  //We want to sum till (n-1)th index na
    cout<<digit_sum(123456);
    return 0;
}
