#include<bits/stdc++.h>
using namespace std;

void generate(string &s , int open , int close , vector<string> &v){
    if(open ==0 && close==0){
        v.push_back(s);
        return;
    }
    if(open >0){
        s.push_back('(');
        generate(s,open-1,close,v);
        s.pop_back();
    }
    if(close >0){
        if(open<close){
            s.push_back(')');
            generate(s,open,close-1,v);
            s.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans ;
    string s = "";
    generate(s,n,n,ans);
    return ans;        
}

int main(){
    vector<string> nas = generateParenthesis(3);
    for(auto &i:nas) cout<<i<<" ";
    return 0;
}