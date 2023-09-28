/*Question 
https://www.codechef.com/problems/ODTPIC?tab=statement
https://www.codechef.com/problems/CHEFQUE
*/
#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"
#define gap cout<<endl;
using namespace std;

int main(){
    bitset<8> v("0111");    //Indexing is done from right to left
    bitset<8> b(14);   //1110
    cout<<v; gap
    cout<<b; gap
    bitset<8> b4{"ABBA", size_t(4), /*0:*/'A', /*1:*/'B'}; // A ka value 0 aur B ka 1
    cout<<b4;gap

    cout<<v[3] << " " <<b[0]; gap
    cout<<boolalpha;
    bitset<5>t;
    t.set();
    cout<<t.all(); gap
    cout<<t.test(3); gap

    bitset<4>wth;
    wth.set();      //1111
    wth.reset(3);   //0111
    string hh = wth.to_string();
    cout<<hh<<" "<<hh[0]; gap

    bitset<20> n("11011001");
    long long int x = n.to_ullong();
    cout<<x; gap

    bitset<4> b1(14), b2(4);
    cout<<(b1&b2); gap
    cout<<(b1|b2); gap
    cout<<(b1^b2); gap
    // cout<<b1<<" "<< b2; gap
    cout<<(~b1); gap
    cout<<(b1 <<  2); gap
    return 0;
}