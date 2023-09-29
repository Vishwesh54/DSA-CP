#include<bits/stdc++.h>
using namespace std;

void permute(vector<int>&nums,vector<vector<int>>&ans ,vector<int>&curr ,vector<int> &freq){
    if(curr.size() == nums.size()){
        ans.push_back(curr);
        return ;
    }

    for(int i=0 ; i<nums.size() ;i++){
        if(!freq[i]){
            freq[i]=1;
            curr.push_back(nums[i]);
            permute(nums,ans,curr,freq);
            freq[i]=0;
            curr.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>curr , freq(nums.size(),0);
    permute(nums,ans,curr,freq);
    return ans;
}

int main(){
    vector<int>v={1,2,3};
    auto it = permute(v);
    for(vector<int> i:it){
        for(int j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}