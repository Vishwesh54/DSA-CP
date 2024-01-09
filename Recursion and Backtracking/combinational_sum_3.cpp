#include<bits/stdc++.h>
using namespace std;

void generate(int ind ,int k, int n ,vector<int> &curr ,vector<vector<int>> &ans){
    if(curr.size()==k || curr.size()>k){
        if(n==0)
            ans.push_back(curr);
        return;
    }
    for(int i=ind;i<=9;i++){
        if(i>n) break;
        curr.push_back(i);
        generate(i+1,k,n-i,curr,ans);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>>ans;
    vector<int>temp;
    generate(1,k,n,temp,ans);
    return ans;
}

int main(){
    auto it=combinationSum3(3,9);
    for(vector<int> i:it){
        for(int j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}