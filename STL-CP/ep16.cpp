#include<bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ic(input) ll input; cin>>input;
#define fc(input) ld input; cin>>input;
#define sc(input) string input; cin >> input;
#define all(nums) nums.begin(),nums.end()
#define Si(nums) nums.size()
#define for0(n) for (ll i = 0; i < n; i++)
#define for1(n) for (ll i = 1; i <= n; i++)
#define fors(n) for (ll i = 0; i < n - 1; i++)
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define vll vector<ll>
#define vi vector <int>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
using namespace std;

const int N=1e5 + 10;
int hsh[N][26];

void solve(){
    for0(N){
        for(int j=0 ; j <26 ;j++){
            hsh[i][j]=0;
        }
    }
    ic(n) ic(q) sc(s)
    for0(n){
        hsh[i+1][s[i] - 'a']++;  //To make 1 indexed array i+1
    }
    
    for(int i=0 ;i<26 ;i++){
        for(int j=1 ;j<=n ;j++){
            hsh[j][i] += hsh[j-1][i];
        }
    }
    while (q--)
    {
        ic(l) ic(r)
        int oddct=0;
        for(int i=0 ;i<26 ;i++){
            int charct =hsh[r][i] - hsh[l-1][i]; 
            if(charct&1) oddct++;
        }
        cout<<(oddct >1 ? "NO":"YES")<<endl;
    }
    
}

int main(){
    io;
    ic(t)
    while(t--){
        solve();
    }
    return 0;
}

/*Sample input
2
5 5
abcec
1 2
2 5
3 5
1 5
1 4
5 5
aabbc
1 2
2 5
3 5
1 5
1 4
*/