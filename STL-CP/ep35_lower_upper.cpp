#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v{ 10, 20, 30, 30, 30, 40, 50 };   //vector must be sorted, SIZE is 7
	cout << "Vector contains :";
	for (int i = 0; i < v.size(); i++)
		cout << " " << v[i];
	cout << "\n";

	vector<int>::iterator low1, low2, low3 ,low4 ,low5;
	
	low1 = lower_bound(v.begin(), v.end(), 30);
	low2 = lower_bound(v.begin(), v.end(), 35);
	low3 = lower_bound(v.begin(), v.end(), 55);     
    low4 = lower_bound(v.begin()+2, v.end() ,25);
    low5 = lower_bound(v.begin()+4, v.end()-1 ,45);

	cout << "\nlower_bound for element 30 at position : " << (low1 - v.begin());
	cout << "\nlower_bound for element 35 at position : " << (low2 - v.begin());
	cout << "\nlower_bound for element 55 at position : " << (low3 - v.begin());
	cout << "\nlower_bound for element 25 at position : " << (low4 - v.begin());
	cout << "\nlower_bound for element 45 at position : " << (low5 - v.begin());
    cout<<endl;

    auto 
    up1 = upper_bound(v.begin() ,v.end() , 10),
    up2 = upper_bound(v.begin() ,v.end() , 36),
    up3 = upper_bound(v.begin() ,v.end() , 51),
    up4 = upper_bound(v.begin()+5 ,v.end() , 15);

    cout<<"\nupper_bound for element 10 at position : "<<up1 - v.begin() ;
    cout<<"\nupper_bound for element 36 at position : "<<up2 - v.begin() ;
    cout<<"\nupper_bound for element 51 at position : "<<up3 - v.begin() ;
    cout<<"\nupper_bound for element 15 at position : "<<up4 - v.begin() <<endl;


	set<int> se = {1,2,6,8,9};
	auto it1 = se.lower_bound(2),
		it2 = se.upper_bound(2);
	cout<<*it1<<endl;
	cout<<*it2<<endl;
	return 0;
}
