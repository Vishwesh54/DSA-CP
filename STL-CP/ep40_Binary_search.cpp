#include<iostream>
using namespace std;

int main(){
    int  n = 6;
    int v[] ={1,2,5,6,8,9};
    cout<<"Enter a element : ";
    int element ;
    cin>>element;
    int low = 0 , high = n-1 ,ind=-1;

    while (low <= high){      //if you write (high-low >= 0) also works 
        int mid=(low+high)/2;
        if(v[mid]>element){
            high=mid-1;
        }
        else if(v[mid]<element){
            low=mid+1;
        }
        else{
            ind=mid;
            break;
        }
    }   

    if(ind==-1){
        cout<<"Element Not found ";
    }
    else{
        cout<<"The Element "<<element<<" is found at index "<<ind;
    }

    return 0;
}