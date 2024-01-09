#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

void generate(int ind,vector<vector<int>>&ans ,vector<int> &curr ,vector<int> &nums){
    ans.push_back(curr);
    for(int i=ind;i<nums.size();i++){
        if(i>ind && nums[i]==nums[i-1]) continue;
        curr.push_back(nums[i]);
        generate(i+1,ans,curr,nums);
        curr.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    vector<int>temp;
    generate(0,ans,temp,nums);
    return ans;
}

int main(){
    vector<int>v={1,2,2};
    auto it = subsetsWithDup(v);
    for(vector<int> i:it){
        if(i.empty()){
            cout<<"[]";
        }
        else{
            for(int j:i){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}