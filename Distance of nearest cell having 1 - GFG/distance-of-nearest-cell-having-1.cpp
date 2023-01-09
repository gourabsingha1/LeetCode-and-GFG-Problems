//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
public:
    void bfs(vector<vector<int>>& mat){
        int n = mat.size(), m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(mat[i][j]){
                    q.push(make_pair(make_pair(i, j), 0));
                    vis[i][j] = 1;
                }
            }
        }
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(q.size()){
            int t = q.size();
            while(t--){
                int x = q.front().first.first, y = q.front().first.second, dist = q.front().second;
                mat[x][y] = dist;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int dx = x + dir[i][0], dy = y + dir[i][1];
                    if(isValid(dx, dy, n, m) && !vis[dx][dy]){
                        q.push(make_pair(make_pair(dx, dy), dist + 1));
                        vis[dx][dy] = 1;
                    }
                }
            }
        }
    }
    bool isValid(int i, int j, int n, int m){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    vector<vector<int>> nearest(vector<vector<int>>& mat) {
        bfs(mat);
        return mat;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends