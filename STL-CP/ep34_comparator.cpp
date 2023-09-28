#include<bits/stdc++.h>
using namespace std;

bool should_i_swap(int a ,int b){   
    if(a<b) return true;    //For descending order if a>b we do swap na
    return false;
}

/*Sorts first in ascending order and second in descending order 
   if first of both are equal 
*/
bool should_i_swap_pairs(pair<int,int> a ,pair<int,int> b){   
    if(a.first != b.first){
        if(a.first > b.first ) return true;
        return false;
    }
    else{
        if(a.second < b.second) return true;
        return false;
    }
}

/* For inbuit sort function the comparator works quite opposite */
bool cmp(pair<int,int> a ,pair<int,int> b){
    if(a.first != b.first){
        if(a.first > b.first ) return false;
        return true;
    }
    else{
        if(a.second < b.second) return false;
        return true;
    }
}

/*Shortcut for the above*/
bool cmpo(pair<int,int> a ,pair<int,int> b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    else{
        return a.second > b.second;
    }
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif
    int n;
    cin>>n;
   /* 
    vector<int> a(n);
    for(int i=0 ; i<n ;i++){
        cin>>a[i];
    }
    
    for(int i=0 ;i<n ;i++){
        for(int j=i+1 ;j<n ;j++){
            if(a[i] < a[j]){        // On the basis of this logic Array is sorted 
                swap(a[i],a[j]);   
            }
        }
    }

    for(int i=0 ;i<n ;i++){
        for(int j=i+1 ;j<n ;j++){
            if(should_i_swap_pairs(a[i] ,a[j])){    
                swap(a[i],a[j]);   
            }
        }
    }
    */

    vector<pair<int,int>> p(n);
    for(int i=0 ;i<n ;i++){
        cin>>p[i].first>>p[i].second ;
    }

    /*
    for(int i=0 ;i<n ;i++){
        for(int j=i+1 ;j<n ;j++){
            if(should_i_swap(p[i] ,p[j])){    
                swap(p[i],p[j]);   
            }
        }
    }
    */
    sort(p.begin() , p.end() ,cmpo);

    for(int i=0 ; i<n ;i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    cout<<endl;

   
    return 0;
}