/* Works for even STACK as well just change the functions */

#include<bits/stdc++.h>
using namespace std;

void insert_at_correct_position(vector<int> &v ,int temp){
    if(v.size() == 0 || v.back() <= temp){      // >= for decreasing order
        v.push_back(temp);
        return;
    }

    int val = v.back();
    v.pop_back();

    insert_at_correct_position(v,temp);

    v.push_back(val);
}

void sort(vector<int> &v){
    if(v.empty())     // if(v.size() == 1) this also works
        return;
    
    int temp = v.back();
    v.pop_back();

    sort(v);

    insert_at_correct_position(v,temp);
}

int main(){
    vector<int> V {1,5,6,2,3,7,1,-1,-8,100};
    sort(V);
    for(int i:V) cout<<i<<" ";
    return 0;
}