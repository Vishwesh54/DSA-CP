#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>s(wordList.begin(),wordList.end());
    queue<pair<string,int>>q;

    q.push({beginWord,1});
    s.erase(beginWord);

    while(!q.empty()){
        auto [word,level] = q.front();
        q.pop();
        if(word==endWord)
            return level;
        for(int i=0;i<word.length();i++){
            char og = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(s.find(word)!=s.end()){
                    s.erase(word);
                    q.push({word,level+1});
                }
            }
            word[i]=og;
        }
    }
    return 0;
}

int main(){
    
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    int ans = ladderLength(startWord, targetWord, wordList);
    cout << ans;
    
    return 0;
}