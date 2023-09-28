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

const int N = 1e7 +10;
ll arr[N];

int main(){
    ic(n) 
    ic(m)
    while(m--){
        ic(a) ic(b) ic(k)
        arr[a] +=k;
        arr[b+1] -=k;
    }
    for1(N){
        arr[i]+=arr[i-1];
    }
    cout<<*max_element(arr , arr+N);
    
    return 0;
}