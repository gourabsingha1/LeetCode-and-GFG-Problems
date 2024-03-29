class Solution {
public:
    // memoization
    int helper(int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(n < 0 || m < 0 || obstacleGrid[n][m]) {
            return 0;
        }
        if(n == 0 && m == 0) {
            return 1;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        
        int left = helper(n - 1, m, obstacleGrid, dp);
        int up = helper(n, m - 1, obstacleGrid, dp);
        return dp[n][m] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, m - 1, obstacleGrid, dp);
    }
};