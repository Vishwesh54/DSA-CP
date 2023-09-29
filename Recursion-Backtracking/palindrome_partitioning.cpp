#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s ,int low ,int high){
    while(low<high){
        if(s[low]!=s[high])
            return false;
        low++,high--;
    }
    return true;
}

void solve(int ind,string &s,vector<string> &curr ,vector<vector<string>> &ans){
    if(ind==s.size()){
        ans.push_back(curr);
    }
    else{
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                curr.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>>ans;
    vector<string>path;
    solve(0,s,path,ans);
    return ans;
}

int main(){
    string s="aabb";
    auto it=partition(s);
    for(vector<string> i:it){
        for(string j:i) cout<<j<<" ";
        cout<<endl;
    }   
    return 0;
}