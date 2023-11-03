#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, 1e7));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
        //Flyod Warshall 
		for (int i = 0; i < n; i++) dist[i][i] = 0;

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (dist[i][j] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = i;
			}
		}
		return cityNo;
	}
};


int main() {

	int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}