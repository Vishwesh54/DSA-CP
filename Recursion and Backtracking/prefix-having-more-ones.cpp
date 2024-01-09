#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
    void solve(int n , int ones , int zeroes , vector<string> &ans , string s){
        if(n == 0){
            ans.push_back(s);
            return;
        }
        solve(n-1,ones+1,zeroes,ans,s+'1');
        if(ones > zeroes)
            solve(n-1,ones,zeroes+1,ans,s+'0');
    }
	vector<string> NBitBinary(int N)
	{
	    vector<string>ans;
	    solve(N,0,0,ans,"");
	    return ans;
	}
};

int main(){
    Solution s;
    auto it = s.NBitBinary(4);
    for(auto i:it) cout<<i<<" ";    
    return 0;
}