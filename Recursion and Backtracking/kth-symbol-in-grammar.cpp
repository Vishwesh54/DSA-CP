#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1)    //Base case 
            return 0;
        
        int mid = 1 << (n-2);   //Length of the row n is 2^(n-1) and its mid value is 2^(n-1)/2

        if(k <= mid)
            return kthGrammar(n-1,k);   //1st half of n is same as n-1 so k remains same
        else
            return 1 - kthGrammar(n-1,k-mid);  // Wheareas 2nd half is the complement of n-1
    }
};

/*  Grammar
    n = 1    0
    n = 2    0 1 
    n = 3    0 1 1 0
    n = 4    0 1 1 0 1 0 0 1
    ________________________
    1 based  1 2 3 4 5 6 7 8
*/
int main(){
    Solution s;              
    cout<<s.kthGrammar(4,4);    
    return 0;
}