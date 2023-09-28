#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif

    map<pair<string,string> , vector<int>> m;
    int n;
    cin>>n;
    while(n--){
        string fn,ln;
        cin>>fn>>ln;
        int ct;
        cin>>ct;
        while (ct--)
        {
            int x;
            cin>>x;
            m[{fn,ln}].push_back(x); // m[] is vector now and {} is a pair getting inserted 
            //Since the value of the map is a vector so we use its functions
        }
        
    }
    for(auto &pr : m){
        cout<<pr.first.first<<" "<<pr.first.second<<endl;
        cout<<pr.second.size()<<endl;
        for(auto &i : pr.second){
            cout<<i<<" ";
        }
        cout<<endl;
        // see values will be sorted acc to pair only 
    }

/* Question https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE*/
    /* METHOD 1 
    map<int , multiset<string>> hmm;
    int N;
    cin>>N;
    while(N--){
        int marks;
        string name;
        cin>>name >> marks;
        hmm[marks].insert(name);
    }
 
    for(auto it = hmm.rbegin() ; it!= hmm.rend() ;it++){
        for(auto &i :it->second){
            cout<<i<<" "<<it->first<<endl;
        }
    }
    */

   // METHOD 2 
    multiset<pair<int , string>>hmm;
    int N;
    cin>>N;
    while(N--){                                 
        int marks;
        string name;
        cin>>name >> marks;
        hmm.insert({-marks,name});          //What a LOGIC  If u try to iterate in the reverse order then d comes before a which we dont want 
    }

    for(auto &i : hmm){
        cout<<i.second<<" "<<-i.first<<endl;
    }
    

    /* METHOD 3
    map<int , multiset<string> ,greater<int>> hmm;
    int N;
    cin>>N;
    while(N--){
        int marks;
        string name;
        cin>>name >> marks;
        hmm[marks].insert(name);
    }
 
    for(auto it:hmm){
        for(auto &i :it.second){
            cout<<i<<" "<<it.first<<endl;
        }
    }
    */
    
    return 0;
}
    


/*  INPUT
3
a b 4
1 2 3 4 
d f 3
2 3 4
c d 2
1 2

4
Eve 78
Bob 99
Alice 78
Alice 78
*/