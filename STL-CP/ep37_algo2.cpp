#include<bits/stdc++.h>
using namespace std;
#define gap cout<<endl;

bool is_positive(int x){
    return x>0;
}

void print(deque<int> &d){
    for(int &i:d){
        cout<<i<<" ";
    }
    gap;
}

int main(){
    vector<int> v = {2,3,-5};
    cout<<all_of(v.begin(),v.end(), //All must be +ve then true
            [](int a){return a>0;}); gap      //Lambda Function 

    cout<<all_of(v.begin(),v.end(),is_positive); gap

    cout<<any_of(v.begin(),v.end(),
            [](int a){return a>0;}); gap  //Any one of the +ve then true

    cout<<none_of(v.begin(),v.end(),
            [](int a){return a>0;}); gap  // True if none is +ve mtlab sb -ve hoga

    int arr[] = {-1 -3,-5};
    cout<<(none_of(arr, arr+3 , [](int x){return x>0;})?"TRUE":"FALSE"); gap

    int a[5] = {1,3,6,8,9};
    cout<<(binary_search(a,a+5,3) ? "Element found" : "Not found"); gap

    string s="cba";
    if(next_permutation(s.begin() ,s.end())){
        cout<<s; gap
    }
    // s becomes abc agains
    do{
        cout<<s; gap
    }while(next_permutation(s.begin(),s.end()));

    deque<int>d;
    d.push_back(2);
    d.push_back(3);
    d.emplace_back(4);
    d.push_front(7);
    d.emplace_front(5);
    cout<<"The contents of the deque are"; gap
    print(d);
    

    list<int>l;
    l.push_back(1);
    l.push_back(5);
    l.push_front(46);
    l.push_front(2);
    l.sort();

    array<int,4> brr = {1};
    brr.fill(3);
    cout<<brr[0]<<endl;
    for(auto i:brr) cout<<i<<" "; gap

    vector<vector<vector<int>>> vec(10 , vector<vector<int>> (20 , vector<int>(30)));

    string str="Hello World";
    str.insert(6,"good");
    cout<<str; gap
    return 0;
}