#include<bits/stdc++.h>
using namespace std;

double eps= 1e-6;

double mutilpy(double mid , int n){
    double ans = 1;
    for(int i=0 ; i<n ;i++)
        ans *=mid;
        
    return ans;
}

int main(){ 
    double x;
    cin>>x;
    double low =1 ,high= x;
    while (high - low >eps) // Accuracy of both remains same till 4-5 decimal places
    {
        double mid = (high+low)/2;
        if(mutilpy(mid,2)<x)        
            low = mid;      //We cant just do +1 as it leads to loss of many decimal places 
        else
            high = mid;       
    }
        
    cout<<setprecision(6)<<low<<" "<<high<<endl;
    cout<<pow(x , 0.5);
    return 0;
}