#include<bits/stdc++.h>
using namespace std;

void solve(int ind , vector<int>&nums,vector<vector<int>>&ans){
    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=ind;i<nums.size();i++){
        swap(nums[ind],nums[i]);
        solve(ind+1 , nums,ans);
        swap(nums[ind],nums[i]); //backtracking, similar to pop_back(), Since we had swapped them before 
    }                              // We need to restore its original position 
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    solve(0,nums,ans);
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