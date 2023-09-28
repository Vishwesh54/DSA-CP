#include<bits/stdc++.h>
using namespace std;

void Printmap(map<int, string> &m){
    cout<<"Size is "<<m.size()<<endl;
    for(auto &i:m){     //Acces time O(log(n))
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
}
 

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif
    
    map<int , string>m;
    m[1] = "abc";       // O(log(n))
    m[5] = "cdc";
    m.insert({3,"acd"});
    m.insert(make_pair(4,"afg"));
    m[6];               // this also takes O(log(n))
    //Also value of 6 will be empty string ,if it was int then 0
    
    m[5] = "cde";       //It overrides the previous value as key is unique
    m.insert({5,"ABS"}); // ***THIS WONT BE EVEN ADDED*** 
    Printmap(m);

    auto it = m.find(7);  //O(log(n))
    if(it == m.end()){
        cout<<"NO VALUE"<<endl;
    }
    else{
        cout<<it->first<<" "<<it->second<<endl;
    }

    // m.erase(5);
    if(it != m.end())
        m.erase(it);
    Printmap(m);


/* Given N strings , print unique strings in LEXOGRAPHICAL ORDER
   with their FREQUENCIES 
   N<=10^5  
   |S|<= 100 
*/
    map<string, int>M;
    int n;
    cin>>n;
    for(int i=0 ;i<n ;i++){
        string s; 
        cin>>s;
        M[s]++; // m[s] is 0 initially 
    }

    for(auto &pr : M){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    return 0;
}