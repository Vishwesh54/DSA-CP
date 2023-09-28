//https://www.youtube.com/watch?v=6zhGS79oQ4k&ab_channel=takeUforward
#include<bits/stdc++.h>
using namespace std;


// Smallest index such that arr[ind] >= x

int lower_bound(vector<int> &arr , int element){
    int n=arr.size();
    int low = 0 , high = n-1 , ans=n;
    while(low <= high){
        int mid = (high + low)/2;
        if(arr[mid] >= element){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

// Smallest index such that arr[ind] > x
int upper_bound(vector<int> &arr , int element){
    int n=arr.size();
    int low = 0 , high = n-1 ,ans=n;
    while(low <= high){
        int mid = (high + low)/2;
        if(arr[mid] > element){   
            ans=mid;
            high =mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int  n = 6;
    vector<int> v ={1,2,5,6,8,9};
    int element ;
    cout<<"Enter an element : ";
    cin>>element;

    int lb = lower_bound(v,element);
    cout<<"The lower bound of "<<element<<" is "<<(lb == 6? -1:v[lb])<<endl;

    int ub = upper_bound(v,element);
    cout<<"The upper bound of "<<element<<" is "<<(ub == 6? -1:v[ub]);
    
    return 0;
}