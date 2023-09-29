#include<bits/stdc++.h>
using namespace std;

void combination(int ind , string &digits , string &curr , string mapping[] , vector<string> &ans){
    if(ind == digits.size()){
        ans.push_back(curr);
        return;
    }

    string letters = mapping[digits[ind]-'0'];  // digits[ind] is a char to get integer value subtract '0' 

    for(int i=0 ; i<letters.size() ; i++){
        curr.push_back(letters[i]);
        combination(ind+1,digits,curr,mapping,ans);
        curr.pop_back();   //Backtracking
    }

}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.empty())
        return ans;

    string phone_map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; //Mapping for digits 0-9  
    string curr;
    combination(0,digits,curr,phone_map,ans);

    return ans;
}

int main(){
    string s = "234";
    vector<string>ans = letterCombinations(s);    
    for(string i:ans){
        cout<<i<<" ";
    }
    
    return 0;
}