#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n;i++) cin>>v[i];

    cout<<*max_element(v.begin()+3 , v.end())<<endl;   

    int sum = accumulate(v.begin() , v.end() , 0);
    cout<<sum<<endl;

    int ct = count(v.begin() , v.end() ,6);
    cout<<"Element 6 is present "<<ct<<" times"<<endl;

    auto it = find(v.begin() , v.end() , 6);
    if(it != v.end()){
        cout<<"Element is at index "<<it- v.begin()<<endl;
    }
    else{
        cout<<"Element Not found"<<endl;
    }

    reverse(v.begin() +2 , v.end());

    for(int i=0 ; i< n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    string s = "abcdef";
    reverse(s.begin()+2 , s.end()-1);
    cout<<s;
    return 0;
}