/*
https://leetcode.com/problems/count-primes/
https://codeforces.com/problemset/problem/230/B
https://codeforces.com/contest/776/problem/B
*/
#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

const int N = 1e7+10;
vector<bool> prime(N,1);
vector<int> lp(N) ,hp(N); //lowest and highest prime

int main(){
    int n;
    cin>>n;
    prime[0]=prime[1]=false;
    for(int i=2 ;i <=n;i++){
        if(prime[i] == true){
            lp[i] =hp[i] =i;
            for(int j=2*i ;j<=n;j+=i){
                prime[j]=false;
                hp[j]=i;
                if(lp[j]==0) lp[j]=i;
            }
        }
    }

    // for(int i=1 ;i<=n;i++){ 
    //     cout<<i<<"--> "<<lp[i]<<" "<<hp[i]<<endl;
    // }

    int num,num1,num2;
    cin>>num;
    num2=num1=num;
    vector<int>prime_factors,distinct_prime_factors;
    while(num1>1){
        int x =lp[num1];
        while(num1%x == 0){
            num1/=x;
            prime_factors.push_back(x);
        }
    }
    cout<<"Prime factors of "<<num<<" are : ";
    for(auto i:prime_factors) cout<<i<<" "; gap


    while(num2>1){
        int x=lp[num2];
        while(num2%x == 0){
            num2/=x;
        }
        distinct_prime_factors.push_back(x);
    }
    cout<<"Distinct Prime factors of "<<num<<" are : ";
    for(auto i:distinct_prime_factors) cout<<i<<" "; gap


    cout<<"Count of each prime factors are :";  gap
    map<int,int>m;
    while(num>1){
        int prime_factor = lp[num];
        while(!(num % prime_factor)){
            num/=prime_factor;
            m[prime_factor]++;
        }
    }
    for(auto i:m) cout<<i.first<<" "<<i.second<<endl;
}