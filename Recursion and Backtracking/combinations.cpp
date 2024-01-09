#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std::chrono;
#define gap cout<<endl;
using namespace std;
  
//Method 1
void picknonpick(int idx, int k, vector<int>& current, int n,vector<vector<int>> &ans) {
    if (current.size() == k) {
        ans.push_back(current);
        return;
    }
    if (idx > n) {
        return;  // Stop when index exceeds the range [1, n]
    }

    current.push_back(idx);
    picknonpick(idx + 1, k, current, n,ans);
    
    current.pop_back();
    picknonpick(idx + 1, k, current, n,ans);
}


//Method2   Remember this one
void helper(int idx, int k,vector<int>&current,int n,vector<vector<int>> &ans){
    if(current.size()==k){    // base case
        ans.push_back(current);
        return;
    }
    
    for(int i=idx;i<n+1;i++){
        current.push_back(i);  //consider the current element i
        helper(i+1,k,current,n,ans); // generate combinations
        current.pop_back(); //proceed to next element
    }
}


vector<vector<int>> combine(int n, int k) {
    vector<int> current;
    vector<vector<int>> ans;
    picknonpick(1, k, current, n,ans);
    return ans;
}

int main(){
    auto start = high_resolution_clock::now();
    auto it=combine(5,3);
    for(auto i:it){
        for(auto j:i){
            cout<<j<<" ";
        }
        gap
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    return 0;
}