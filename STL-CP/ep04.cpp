#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define endl "\n"

int main(){
	io
	cout<<(3==2)<<endl;
	string s;
	getline(cin,s); cout<<s<<endl;

	int t=1;
	cin>>t;
	cin.ignore();
	while (t--)
	{
		string str;
		getline(cin,str);
		cout<<str<<endl;
	}
	
	return 0;
}

