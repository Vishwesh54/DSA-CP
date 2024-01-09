#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    long long toh(int N, int from, int to, int aux) {
        long long ans = 0;
        
        if(N == 0){
            return 0;
        }
        
        ans += toh(N-1,from,aux,to);
        printf( "move disk %d from rod %d to rod %d\n" , N, from, to);
        ans++;
        ans += toh(N-1,aux,to,from);
        
        return ans;
    }

};

int main(){
    Solution s;
    int n; cin>>n;
    cout<<s.toh(n,1,3,2);   // 1 => disc 1 , similarly others as well
    return 0;
}   