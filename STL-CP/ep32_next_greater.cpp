#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> v,int n){
    vector<int> nge(n);
    stack<int> st;
    for(int i=n-1 ; i>=0 ;i--){
        while(!st.empty() && v[i] >= st.top())
            st.pop();
        nge[i] = st.empty() ? -1:st.top();
        st.push(v[i]);
    }
    return nge;
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt" , "r" ,stdin);
    //     freopen("output.txt" , "w" ,stdout);
    // #endif

    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0 ; i<n ;i++){
        cin>>v[i];
    }
    vector<int>nge = NGE(v,n);

    for(int i=0 ; i<n ;i++){
        cout<<nge[i]<<" ";
    }
    
    return 0;
}


/* INPUT 
6
4 5 2 25 7 8
*/