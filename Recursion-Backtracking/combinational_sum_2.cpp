#include<bits/stdc++.h>
using namespace std;

void generate(int ind, int k ,vector<int>&nums , vector<int>&curr ,vector<vector<int>>&ans){
    if(k==0){
        ans.push_back(curr);
        return;
    }
    for(int i=ind;i<nums.size();i++){
        if(nums[i]>k) break;
        if(i>ind && nums[i]==nums[i-1]) continue;
        curr.push_back(nums[i]);
        generate(i+1,k-nums[i],nums,curr,ans);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>>ans;
    vector<int>temp;
    generate(0,target,candidates,temp,ans);
    return ans;
}


int main(){
    vector<int> v = {10,1,2,7,6,1,5};
    auto it=combinationSum2(v,8);
    for(vector<int> i:it){
        for(int j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}