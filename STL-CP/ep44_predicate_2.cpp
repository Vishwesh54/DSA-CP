/*Question 
https://www.spoj.com/problems/AGGRCOW/ 
*/
#include<bits/stdc++.h>
using namespace std;

bool canPlacecows(int minDist ,vector<int> &positions ,int c){
    int lastpos = -1;
    for(int i=0 ; i<positions.size() ;i++){
        if(positions[i] - lastpos >= minDist || lastpos ==-1){
            c--;
            lastpos = positions[i];
        }
        if(c==0) break;
    }
    return c==0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,cows;
        cin>>n>>cows;
        vector<int>positions(n);
        for(int i=0 ; i<n ;i++){
            cin>>positions[i];
        }
        sort(positions.begin() , positions.end());  // Need to sort obvi.

        // T T T T F F F F F F F ...    If we keep on increasing the largest minimum distance(lmd) then at some point ,
        int low = 0 ,high = 1e9 ,ans=0; // All the cows wont fit on the straight line so we find the last true value (lmd value)
        while(low <= high){
            int mid = (high + low)/2;
            if(canPlacecows(mid,positions,cows)){   // If we can place all the cows with lmd as mid 
                ans=mid;                            // We update the ans
                low =mid+1;                         // And go on searching to the right of this mid as there might exists other T values
            }
            else{
                high = mid - 1;     // We cant place all the cows also => we cant even keep the lmd as mid or ahead of mid
            }                       // Hence we shift our high to mid-1 to exclude that part
        }

        //TC N * log(10^9)
        cout<<ans<<endl;
    }
    return 0;
}

/*Practice :https://leetcode.com/problems/minimum-speed-to-arrive-on-time/*/