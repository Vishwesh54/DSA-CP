#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif

    stack<int>s;
    s.push(2);
    s.push(3);
    s.emplace(4);
    s.emplace(5);
    stack<int> s1=s;

    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    cout<<"Size of the stack s is :"<<s.size()<<endl;

    queue<string> q;
    q.push("abc");
    q.push("xyz");
    q.emplace("bcd");
    q.emplace("hmm");

    cout<<q.front()<<" "<<q.back()<<endl;

    queue<string>q1;
    q1.push("ad");
    q1.push("sd");
    q1.push("d");

    q.swap(q1);
    
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }   //This empties the queue after while loop ends
    
    
    return 0;
}