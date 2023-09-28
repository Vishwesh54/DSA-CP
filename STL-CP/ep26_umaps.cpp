#include<bits/stdc++.h>
using namespace std;

void Printmap(unordered_map<int, string> &m){
    cout<<"Size is "<<m.size()<<endl;
    for(auto &i:m){      // Access time O(1)
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
}
 

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif
    
    unordered_map<int , string>m;
    m[1] = "abc";       // O(1))
    m[5] = "cdc";
    m.insert({3,"acd"});
    m.insert(make_pair(4,"afg"));
    m[6];               // this also takes O(1))
    //Also value of 6 will be empty string ,if it was int then 0
    
    m[5] = "cde";       //It overrides the previous value as key is unique
    m.insert({5,"ABS"}); // ***THIS WONT BE EVEN ADDED*** 
    Printmap(m);
    
/* Given N strings and Q queries ,In each query your are
   given a string print the frequency of that string
   N<=10^5  
   |S|<= 100 
   Q <=10^5
*/
    unordered_map<string, int>M;
    int n;
    cin>>n;
    for(int i=0 ;i<n ;i++){
        string s; 
        cin>>s;
        M[s]++; // m[s] is 0 initially 
    }
    
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        cout<<M[s]<<endl;
    }
    return 0;

}