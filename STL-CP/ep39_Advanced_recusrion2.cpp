#include<bits/stdc++.h>
using namespace std;

void generate(vector<int>& arr , int i , vector<int>& nums ,vector<vector<int>> &v){
    if(i==nums.size()){
        v.push_back(arr);
        return;
    }
    generate(arr,i+1,nums,v);
    arr.push_back(nums[i]);
    generate(arr,i+1,nums,v);
    arr.pop_back();

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int>arr;
    generate(arr,0,nums,ans);
    return ans;        
}

int main(){
    vector<int> v {1,2,3};
    vector<vector<int>>temp = subsets(v);
    for(auto i:temp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}