/*#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0 ; i<n ;i++){
		cin>>a[i];
	}
	int p=1;
    for (int i = 0; i < n; i++)
    {
        p=p*a[i];
    }
    cout<<p;
	string s;
	while(p>0){
		s.push_back(p%10);
		p/=10;
	}
    if(s[0]=='2' || s[0]=='3' || s[0]=='5'){
        cout<<"YES\n";
    }
    else{
        cout<<"NO"<<endl;
    }

}

*/

/*
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		long decimal=0;
		int b;
		for(int i=0; i<n ;i++){
			long dec=0;
			b=int(s[i]-'0');
			dec=b*pow(2,n-1-i);
			decimal+=dec;
		}
		cout<<decimal<<endl;
	}
}

*/

/*
#include<bits/stdc++.h>
using namespace std;

char upper(char c){
    return 'A'+(c-'a');                                 //C-A = c- a
}
int main(){
    while(true){
        string s;
        cin>>s;
        if(s.size()==0){
            break;
        }
        for(int i=0 ; i<s.size() ; i++){
            s[i]=upper(s[i]);
        }

        cout<<s<<endl;
    }   
    return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long int a[n][n];
		a[0][0]=1;
		for (int i = 1; i < n; i++)
		{
			a[i][0] =1;
			a[i][i] =1;
			for (int j = 1; j < i; j++)
			{
				a[i][j]= a[i-1][j-1] + a[i-1][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;			
		}
	}	
	return 0;
}