#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

void display(pair<int , string> &p){
    cout<<p.first<<" "<<p.second<<endl;
}

void printvec(vector<int> v){
    cout<<"Size of the vector is "<<v.size()<<endl; //O(1)
    for(int i=0 ;i <v.size() ;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    /*
    pair<int , string> p;
    p= make_pair(1 ,"Abc");
    display(p);

    pair<int ,string> p1(2,"Def");
    display(p1);

    pair<int ,string> p2{3 ,"Ghi"};
    display(p2);

    pair<int ,string> p3;
    p3 = {4 , "Jkl"};
    display(p3);

    pair<int ,string> p4 = p2;  pair<int ,string> p6(p2);   //Two ways to copy 
    display(p4);                display(p6);

    pair<int ,string> &p5 = p1;  //Passed by refference so value gets changed  
    p5.first = 7;
    display(p1);
    

    pair<int ,int> p_array[3];
    p_array[0] = {1,2};
    p_array[1] = {3,4};
    p_array[2] = {5,6};
    swap(p_array[0] , p_array[2]);

    for(int i=0 ;i<3 ;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
    */

    vector<int> v;
    int n ; cin>>n;
    for(int i=0 ;i<n ;i++) {
        int x; cin>>x;
        v.push_back(x);
    }
    // printvec(v);

    // v.pop_back();
    vector<int> &v2= v; 
    v2.push_back(5);
    printvec(v2);
    printvec(v);

    return 0;
}