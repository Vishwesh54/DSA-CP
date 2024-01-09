#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

//Method 1
void Subsequence_with_k1(int i, int k ,vector<int> &ans ,int sum ,vector<int>&nums){
    if(i==nums.size()){
        if(sum==k){
            for(int i:ans) cout<<i<<" ";
            cout<<endl;
        }
        return;
    }

    ans.push_back(nums[i]);
    sum+=nums[i];
    Subsequence_with_k1(i+1,k,ans,sum,nums);

    ans.pop_back();
    sum-=nums[i];
    Subsequence_with_k1(i+1,k,ans,sum,nums);

}

//Method 2
void Subsequence_with_k(int i, int k ,vector<int> &ans ,int sum ,vector<int>&nums){
    if(i==nums.size()){
        if(sum==k){
            for(int i:ans) cout<<i<<" ";
            cout<<endl;
        }
        return;
    }

    ans.push_back(nums[i]);
    Subsequence_with_k(i+1,k,ans,sum+nums[i],nums);

    ans.pop_back();
    Subsequence_with_k(i+1,k,ans,sum,nums);

}

bool exists_with_sumk(int i, int k ,vector<int> &ans ,int sum ,vector<int>&nums){
    if(i==nums.size()){
        if(sum==k){
            // for(int i:ans) cout<<i<<" ";
            // cout<<endl;
            return true;
        }
        return false;
    }

    ans.push_back(nums[i]);
    if(exists_with_sumk(i+1,k,ans,sum+nums[i],nums))
        return true;

    ans.pop_back();
    if(exists_with_sumk(i+1,k,ans,sum,nums))
        return true;

    return false;
}

int no_of_subs(int i, int k ,int sum ,vector<int>&nums){
    if(i==nums.size()){
        if(sum==k){
            return 1;
        }
        return 0;
    }

    int left = no_of_subs(i+1,k,sum+nums[i],nums);
    int right = no_of_subs(i+1,k,sum,nums);

    return left + right;
}

int main(){
    vector<int> nums= {1,2,3,2,4};
    vector<int>ans;
    Subsequence_with_k1(0,4,ans,0,nums);
    cout<<boolalpha<<exists_with_sumk(0,4,ans,0,nums)<<endl;
    cout<<no_of_subs(0,4,0,nums);gap
    
    return 0;
}