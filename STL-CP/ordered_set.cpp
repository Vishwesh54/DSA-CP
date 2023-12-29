#include<bits/stdc++.h>
using namespace std;

/* SET with additional functionalities 
  1. find_by_order(k) -> returns ITERATOR of the kth element (0 indexing) => RANDOM ACCESSING
  2. order_of_key(k)  -> Returns the number of elements STRICTLY SMALLER than k.
*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>   
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
/* For MULTISET -> replace less with less_equal
   For Descending order ->  replace less with greater ,
//      In that case order_of_key(k) -> Returns the number of elements STRICTLY GREATER than k.
*/


template<class T>
using ordered_set_decreasing = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update> ;

int main() {
	ordered_set<int> A; // declaration

	// Inserting elements - 1st query
	A.insert(1);
	A.insert(10);
	A.insert(2);
	A.insert(7);
	A.insert(2);  // ordered set only contains unique values

	// A contains
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	cout << endl;

	// finding kth element - 4th query
	cout << "0th element: " << *A.find_by_order(0) << endl;
	cout << "1st element: " << *A.find_by_order(1) << endl;
	cout << "2nd element: " << *A.find_by_order(2) << endl;
	cout << "3rd element: " << *A.find_by_order(3) << endl;
	cout << endl;

	// finding number of elements smaller than X - 3rd query
	cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl; // 2
	cout << "No. of elems smaller than 11: " << A.order_of_key(11) << endl; // 4
	cout << "No. of elems smaller than 1: " << A.order_of_key(1) << endl; // 0
	cout << endl;

	// lower bound -> Lower Bound of X = first element >= X in the set
	cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
	cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
	cout << endl;

	// Upper bound -> Upper Bound of X = first element > X in the set
	cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
	cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
	cout << endl;

	// // Remove elements - 2nd query
	A.erase(1);
	A.erase(11); // element that is not present is not affected

	// A contains
	cout << "A = ";
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	cout << endl;


	ordered_set_decreasing<int>s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(6);
	s.insert(7);
	cout << "s = ";
	for (auto i : s)
		cout << i << " ";
	cout << endl;
	cout << endl;

	cout << "0th element: " << *s.find_by_order(0) << endl;
	cout << "1st element: " << *s.find_by_order(1) << endl;
	cout << "2nd element: " << *s.find_by_order(2) << endl;
	cout << "3rd element: " << *s.find_by_order(3) << endl;
	cout << endl;

	// finding number of elements greater than X - 3rd query
	cout << "No. of elems greater than 6: " << s.order_of_key(6) << endl; 
	cout << "No. of elems greater than 11: " << s.order_of_key(11) << endl; 
	cout << "No. of elems greater than 1: " << s.order_of_key(1) << endl; 
	cout << "No. of elems greater than 0: " << s.order_of_key(0) << endl; 
	cout << endl;
}