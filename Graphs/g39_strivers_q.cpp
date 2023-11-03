#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumMultiplications(vector<int> &arr,int start, int end){
        queue<int>q;
        vector<bool> vis(1e5,0);
        
        q.emplace(start);
        vis[start]=1;

        int level=0;
        while(!q.empty()){
            int curlvl=q.size();
            while(curlvl--){
                int node=q.front();
                q.pop();
                
                if(node==end)
                    return level;
                
                for(int it:arr){
                    int num = (it*node)%(100000);
                    if(!vis[num]){
                        q.push(num);
                        vis[num]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

int main(){
    int start = 3, end = 30;
    vector<int> arr = {2, 5, 7};
    Solution obj;

    int ans = obj.minimumMultiplications(arr, start, end);
    cout << ans;
    
    return 0;
}