#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];

void merge(int l , int r ,int mid){
    int l_sz = mid -l+1; //From left to right one array 
    int L[l_sz+1];

    int r_sz = r - mid; // r - (mid + 1) +1 
    int R[r_sz+1];
    for(int i=0 ; i<l_sz ;i++){
        L[i]=a[i+l];
    }

    for(int i=0 ; i<r_sz ;i++){
        R[i] = a[i+mid+1];    // mid ke baad wlaa element 
    }

    /*IMP STEP
    When size of both arrays are not same So instead of using again
    while loop that is done in most of the online websites we will simply put 
    a maximum value as elements which are getting compared with this be always less 
    than that max value so alwasys teh remaining values will automatically 
    inserted while merging */

    L[l_sz] = R[r_sz] = INT_MAX;  
    int l_i = 0 , r_i=0;
    for(int i=l ; i<=r ;i++){
        if(L[l_i] <= R[r_i]){
            a[i] = L[l_i];
            l_i++;
        }
        else{
            a[i] = R[r_i];
            r_i++;
        }
    }
}

void merge_sort(int l ,int r){
    if(l<r){
        int mid = (l+r)/2;
        merge_sort(l ,mid);
        merge_sort(mid + 1,r);
        merge(l ,r , mid);
    }
}
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    merge_sort(0 , n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    

    
    return 0;
}