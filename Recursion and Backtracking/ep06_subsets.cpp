#include<bits/stdc++.h>
using namespace std;

void pick_notpick(int i , vector<vector<int>> &ans , vector<int> &temp , vector<int> &nums){
    if(i == nums.size()){
        ans.push_back(temp);
        return;
    }
    
    pick_notpick(i+1,ans,temp,nums);    // Not pick

    temp.push_back(nums[i]);
    pick_notpick(i+1,ans,temp,nums);    // Pick an element
    temp.pop_back();                    // Backtacking step since we are passing it by refference 
}

void forloop(int i , vector<vector<int>> &ans , vector<int> &temp , vector<int> &nums){
    ans.push_back(temp);    // No need to check for base case as its been checked inside the for loop

    for(int ind = i ; ind < nums.size() ; ind++){
        temp.push_back(nums[ind]);

        forloop(ind+1,ans,temp,nums);

        temp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &v){
    vector<vector<int>>ans;
    vector<int>temp;
    // pick_notpick(0,ans,temp,v);
    forloop(0,ans,temp,v);
    return ans;
}

int main(){
    vector<int>v={1,2,3};
    auto it = subsets(v);
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