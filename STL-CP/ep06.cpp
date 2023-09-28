#include<iostream>
using namespace std;
const int b=1e+7;
int arr[b];


int main(){
    int n , m ;
    cin>>n>>m;
    int a[n][m];
    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }

    cout<<"The array is :"<<endl;
    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
        
    }

    arr[b-1]=5;
    cout<<arr[b-1];
       
    return 0;
}