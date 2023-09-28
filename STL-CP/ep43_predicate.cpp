/*Question 
https://www.spoj.com/problems/EKO/ */

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n;
long long m;
long long trees[N];

long long isWoodSufficient(int h){
    long long wood = 0;
    for(int i=0 ;i<n ;i++){     // O(n)
        if(trees[i] >=h )
            wood+= trees[i]-h;
    }
    return wood ;
}

int main(){
    cin>>n>>m;
    for(int i=0 ; i<n ;i++){
        cin>>trees[i];
    }

    long long low = 0 ,high =1e9 ,maximum_height=0; // Let it be H

    // Return values of isWoodSufficient--> T T T T F F F F F F F .... predicate function 
    // Aim is to find last true value
    /*We need to maximise H since if we keep it less than that we will have more amount of wood than required*/
    while (low<=high)
    {   
        int mid = (high +low)/2;
        if(isWoodSufficient(mid)>=m){   
            maximum_height=mid;         // >= means this can be the height so we update H which is locally maximum
            low = mid+1;                // then we try to find some more greater height by shifting low, => mid value increses H increases
        }
        else{                // it isnt sufficient => H is too high we need to bring it down
            high =mid-1;      // So we bring it down by shifting high 
        }
    }
    cout<<maximum_height;
    
    //Time Complexity : O(N log(h))
    return 0;
}