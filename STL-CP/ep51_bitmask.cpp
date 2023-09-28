/*Article 
https://codeforces.com/blog/entry/73558
Question
https://codeforces.com/problemset/problem/1097/B
*/

#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

int main(){
    io;
    int n;
    cin>>n;
    vector <int> masks(n,0);
    for(int i=0 ; i<n ;i++){
        int num_workers;
        cin>>num_workers;
        int mask = 0;
        for(int j = 0 ; j<num_workers ;j++){
            int day;
            cin>>day;
            mask |= (1<<day);
        }   
        masks[i] = mask;
    }
    int max_days=0 ,person1=-1 ,person2=-1;
    for(int i=0 ;i<n;i++){
        for(int j=i+1 ;j<n;j++){
            int intersection = (masks[i]&masks[j]);
            int common_days = __builtin_popcount(intersection); 
            if(common_days > max_days){
                max_days = max(max_days,common_days);
                person1 =i;
                person2 =j;
            }
        }
    }
    cout<<person1<<" "<<person2<<" "<<max_days<<endl;
    // O(N^2)

    /*Input
    5
    4
    1 4 7 9
    6
    2 9 1 7 25 29
    7
    1 23 4 7 9 11 29
    10
    2 28 8 7 9 10 30 21 18 19
    4
    1 11 29 7
    */
    return 0;
}