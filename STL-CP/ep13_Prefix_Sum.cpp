
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

// 1D Array
const int N=1e5 +10;
int a[N] , ps[N];

int main(){
    io;
    ic(n)                               //My method 
    for1(n){                            //ll sum=0;
        cin>>a[i];
        ps[i] = ps[i-1] + a[i];         //sum+=a[i]  ps[i]=sum
    }
    ic(q)
    while(q--){
        ic(l) ic(r)
        cout<<ps[r] - ps[l-1]<<endl;
    }

    return 0;
}



/*  2D Array
const int N=1e3 +10;
int arr[N][N];
ll ps[N][N];

int main(){
    io;
    ic(n)
    for1(n){
        for (int j = 1; j <=n ; j++){
            cin>>arr[i][j];
            ps[i][j] = arr[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }
    ic(q)
    while(q--){
        ic(a) ic(b) ic(c) ic(d)
        cout<<ps[c][d] - ps[c][b-1] - ps[a-1][d] +ps[a-1][b-1]<<endl;
    }
    
}

*/