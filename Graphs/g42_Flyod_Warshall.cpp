#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	void shortest_distance(vector<vector<int>>&adjmat) {
		int n = adjmat.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adjmat[i][j] == -1) 
					adjmat[i][j] = 1e9;
				if(i==j)
                    adjmat[i][i]=0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adjmat[i][j] == 1e9) {
					adjmat[i][j] = -1;
				}
			}
		}
	}
};

int main() {

	int V = 4;
	vector<vector<int>> adjmat(V, vector<int>(V, -1));
	adjmat[0][1] = 2;
	adjmat[1][0] = 1;
	adjmat[1][2] = 3;
	adjmat[3][0] = 3;
	adjmat[3][1] = 5;
	adjmat[3][2] = 4;

	Solution obj;
	obj.shortest_distance(adjmat);

	for (auto row : adjmat) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

	return 0;
}