#include<bits/stdc++.h>
using namespace std;

void printvec(vector<pair<int,int>> &v){
    cout<<"Size of the vector is "<<v.size()<<endl; //O(1)
    for(int i=0 ;i <v.size() ;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}

void printvec(vector<int> &v){
    cout<<"Size of the vector is "<<v.size()<<endl; //O(1)
    for(int i=0 ;i <v.size() ;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif
    vector<pair<int,int>> v = {{1,2} ,{2,3} ,{3,1}};   //Vector of Pairs
    printvec(v);
    vector<pair<int,int>> v1(3);
    for(int i=0 ;i<3 ;i++){
        int x,y;
        cin>>x>>y;
        v1[i] = {x,y};
    }
    printvec(v1);
    

    /*
    int N;
    cin>>N;
    vector<int> vec_arr[N]; // Array of vectors
    for(int i=0 ;i<N ;i++){
        int n;  //size of each vector 
        cin>>n;
        for(int j=0 ;j<n ;j++){
            int x ; cin>>x;
            vec_arr[i].push_back(x);  //vec_arr[i] --> ith vector
        }
    }

    for(int i=0 ;i<N ;i++){
        printvec(vec_arr[i]);
    }
    cout<<vec_arr[0][0];
    */

    vector<vector<int>> vec_vec;      // Vector of Vector 
    int N;
    cin>>N;
    for(int i=0 ; i<N ;i++){
        int n;
        cin>>n;
        vector<int>temp(n);
        for(int j=0 ;j <n ;j++){
            cin>>temp[j];
        }
        vec_vec.push_back(temp);
    }    

    vec_vec[0].push_back(0);
    vec_vec.push_back(vector<int>());
    for(int i=0 ;i<vec_vec.size() ;i++){
        printvec(vec_vec[i]);
    }

    cout<<vec_vec[1][2];

    return 0;
}