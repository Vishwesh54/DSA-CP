#include<bits/stdc++.h> 
using namespace std; 

//Method 1
void subset_add(int i,int sum,vector<int>&curr ,vector<int>&nums ,int n){
    if(i==n){
        curr.push_back(sum);
        return;
    }

    subset_add(i+1,sum+nums[i],curr,nums,n);
    subset_add(i+1,sum,curr,nums,n);
}

//Method 2
void subset_add_for(int ind,int sum,vector<int>&curr ,vector<int>&nums ,int n){
    curr.push_back(sum);

    for(int i=ind ; i<n;i++){
        subset_add_for(i+1,sum+nums[i],curr,nums,n);
    }
}

vector<int> subset_Sums(vector<int> arr, int N){
    vector<int>ans;
    subset_add_for(0,0,ans,arr,N);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int>v {5,2,1};
    vector<int> it;
    it=subset_Sums(v,3);
    for(int i:it){
        cout<<i<<" ";
    }
}