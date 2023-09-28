#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

string isBalanced(string s) {
    stack<char> st;
    unordered_map<char,int> symbols =
    {
        { '[',-1 } , { '(',-2 } , { '{',-3 },
        { ']', 1 } , { ')', 2 } , { '}', 3 } 
    };
    for(char bracket:s){
        if(symbols[bracket] < 0){     //opening bracket 
            st.push(bracket);
        }
        else{               
            if(st.empty()) 
                return "NO";

            char top = st.top();    
            st.pop();                               

            if(symbols[top] + symbols[bracket] != 0) //When the opening and closing brackets are not same in nature 
                return "NO";
        }
    }
    return st.empty() ? "YES":"NO";         //If stack is not empty then false else true
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        cout<<isBalanced(s)<<endl;
    }
    return 0;
}


/* INPUT 
3               
{[()]}          
{[(])}         
{{[[(())]]}} 
*/