#include<bits/stdc++.h>
using namespace std;

//Method 1
vector<vector<int>>res;
void generate(int i, int k ,vector<int> &ans ,int sum ,vector<int>&nums){
    if(i==nums.size() || sum>k){
        if(sum==k){
            res.push_back(ans);
        }
        return;
    }

    ans.push_back(nums[i]);
    generate(i,k,ans,sum+nums[i],nums);

    ans.pop_back();
    generate(i+1,k,ans,sum,nums);
}

vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
    vector<int>temp;
    generate(0,target,temp,0,candidates);
    return res;
}


//Method 2
void combination(vector<int>& nums, int target, vector<int> currComb, int sum, int ind, vector<vector<int>>& ans){
    if(sum>target) return; 
    if(sum==target){
        ans.push_back(currComb); 
        return;
    }
    
    for(int i=ind; i<nums.size(); i++){
        currComb.push_back(nums[i]); 
        combination(nums, target, currComb, sum+nums[i], i, ans); 
        currComb.pop_back(); 
    }  
}

vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> currComb;
    combination(nums, target, currComb, 0, 0, ans);
    return ans;
}


//Method 3
void comb(int i ,int target ,vector<vector<int>> &ans ,vector<int> &nums ,vector<int> &curr){
    if(i==nums.size()){
        if(target==0){
            ans.push_back(curr);
        }
        return;
    }

    if(nums[i]<=target){    // To ensure target never <0 .If it does no point of considering it as it wont be our answer  
        curr.push_back(nums[i]);
        comb(i,target-nums[i],ans,nums,curr);
        curr.pop_back();
    }

    comb(i+1,target,ans,nums,curr);
}

vector<vector<int>> combinationSum3(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> currComb;
    comb(0,target,ans,nums,currComb);
    return ans;
}


// --------------------********--------------------- //
int main(){
    vector<int> v {3,2,6,8,4};
    int k=10;
    auto it=combinationSum3(v,k);
    for(vector<int> i:it){
        for(int j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}