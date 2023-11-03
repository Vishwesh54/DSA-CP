#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
typedef pair<int,pair<int,int>> pii;
    int MinimumEffort(vector<vector<int>> &h){
        int n=h.size() , m=h[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e7));
        priority_queue<pii,vector<pii>,greater<pii>>pq;

        dist[0][0]=0;
        pq.push({0,{0,0}});

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int diff=it.first , x=it.second.first , y=it.second.second;
            if(x==n-1 && y==m-1)
                return diff;
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i] , ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int neweffort = max(diff , abs(h[x][y]-h[nx][ny]));
                    if(neweffort<dist[nx][ny]){
                        dist[nx][ny]=neweffort;
                        pq.push({neweffort,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    Solution obj;
    int ans = obj.MinimumEffort(heights);
    cout << ans;
    return 0;
}