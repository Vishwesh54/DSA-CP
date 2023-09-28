// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/
#include<bits/stdc++.h>
#define pb push_back
#define ic(input) ll input; cin>>input;
#define fc(input) ld input; cin>>input;
#define sc(input) string input; cin >> input;
#define all(nums) nums.begin(),nums.end()
#define rall(nums) nums.rbegin(),nums.rend()
#define Si(nums) nums.size()
#define for0(n) for (ll i = 0; i < n; i++)
#define rep(It,x,y) for(ll It=x; It<y; It++) 
#define ll long long int
#define ld long double
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
using namespace std;

bool Isvowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

vector<string> subsets(string s){
    int sz = Si(s);
    vector<string>ans;
    rep(i,0,(1<<sz)){
        string temp;
        rep(j,0,Si(s)){
            if(i & (1<<j)){
                temp.pb(s[j]);
            }
        }
        if(Si(temp))
            ans.pb(temp);
    }    
    return ans;
}

void solve(){
    ic(n)
    string str[n];
    for0(n){
        cin>>str[i];
    }
    unordered_map<string,int>hsh;
    for0(n){
        set<char>distinct_vw;
        for (char ch : str[i]){
            if(Isvowel(ch)) distinct_vw.insert(ch);
        }
        string vowel_str(all(distinct_vw));
        vector<string> all_subsets=subsets(vowel_str);
        for(auto &i:all_subsets) {
            hsh[i]++;
        }
    }
    ll ans=0;
    for(auto &pair:hsh){
        if(pair.second <3 ) continue;
        ll ct =pair.second;
        ll ways= ct*(ct-1)*(ct-2)/6;
        if(pair.first.size() % 2 ==0) ans-=ways;
        else ans+=ways;
    }   
    cout<<ans;
}   

int main(){
    io;
    ic(t)
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}