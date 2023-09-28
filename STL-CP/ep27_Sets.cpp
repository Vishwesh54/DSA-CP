#include <bits/stdc++.h>
using namespace std;

/*
.begin() -> Returns an iterator pointing to the first element of the set
.end()  -> Returns an iterator pointing next to the last element of the set
.rbegin() -> Returns a reverse iterator pointing to the last element of the set
.rend() -> Returns a reverse iterator pointing before the first element of the set

map -> sorted unique keys...different keys can point to same value..O(log n)..red black tree
unordered_map -> unsorted unique keys..different keys can point to same value..O(1)..hashing...u cannot use it for complex data type like pair,set..
multimap -> a key pointing to more than one value...O(log n)..Red black tree
set -> sorted unique values..no key..O(log n)..red black tree
Unordered_set -> unsorted unique values..no key..O(1)..hashing...u cannot use it for complex data type like pair,set..
multiset -> Duplicate values are allowed...O(log n)..red black tree...u can use this instead of priority queues
*/ 

void printset(set<string> &s){
    cout<<"Size: "<<s.size()<<endl;
    for(auto value:s)
        cout<<value<<endl;
    cout<<endl;
}

void printmultiset(multiset<string>&ms){
    cout<<"Size of Multiset:"<<ms.size()<<endl;
    for(auto valuems: ms)
        cout<<valuems<<endl;
    cout<<endl;
}

int main(){   
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif

    //set follows red black tree implementation...so almost all operations will take O(log n) time
    set <string> s;
    s.insert("abc");//O(log n)
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("xoxo");
    s.insert("abc");//this will be ignored..coz set stores unique values
    
    //U cannot access elements in a set using []..u will have to use .find()
    auto it=s.find("zsdf");//O(log n)
    if(it!=s.end())
        cout<<*it<<endl;
        
    cout<<endl<<"set s:"<<endl;
    printset(s);
    
    set <string> s1(s.begin(),s.end());//Assigning the elements of s to s1
    cout<<"set s1:"<<endl;
    printset(s1);
    
    //U cannot modify an element of the set..but u can erase it and add the element u wished to add to modify the element
    s.erase("abc");
    s.erase(it);
    cout<<"set s:"<<endl;
    cout<<"Size: "<<s.size()<<endl;
    for(auto iter=s.begin();iter!=s.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    
    //Removing elements upto "xoxo"
    s1.erase(s1.begin(),s1.find("xoxo"));//it will remove elements which are present before xoxo
    cout<<endl<<"Set s1:"<<endl;
    printset(s1);
    
    cout<<"Set s in reverse order:"<<endl;
    for(auto it1=s.rbegin();it1!=s.rend();it1++)//Printing the set elements in reverse order
        cout<<*it1<<endl;
    cout<<endl;
    
    /*
    Take n strings as input and print unique strings in lexographical order
    n<=10^5;  |s|<=10^5
    */
    int n;
    cin>>n;
    set<string> ss;
    while(n--)
    {
        string str;
        cin>>str;
        ss.insert(str);
    }
    printset(ss);
    
    //Difference between unordered_set and set is similar to the difference between unordered_map and map..
    //So use Unordered_set when u dont give a shit about the order
    
    /*
    Given n1 strings and q queries 
    In each query a string is Given
    print yes if the string is present in the n1 strings..else no
    */
    int n1;
    cin>>n1;
    unordered_set <string> us;
    while(n1-->0)
    {
        string str1;
        cin>>str1;
        us.insert(str1);
    }
    int q;
    cin>>q;
    while(q--)
    {
        string qs;
        cin>>qs;
        if(us.find(qs)==us.end())
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    
    multiset<string> ms;
    ms.insert("xoxos");
    ms.insert("aiai");
    ms.insert("ajio");
    ms.insert("aiai");//Duplicate values are allowed
    ms.insert("xoxos");
    printmultiset(ms);
    
    auto itms=ms.find("aiai");//this will return pointer to the first instance of aiai
    if(itms!=ms.end())
        ms.erase(itms);//this will erase the aiai which is pointed by itms..i.e. the first aiai
    printmultiset(ms);
    
    ms.erase("xoxos");//this will erase all the instances of xoxos
    printmultiset(ms);
}