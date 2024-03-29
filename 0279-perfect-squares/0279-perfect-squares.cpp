class Solution {
public:
    // memoization
    int helper(int n, vector<int>& dp) {
        if(n == 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int res = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            res = min(res, helper(n - i * i, dp) + 1);
        }
        return dp[n] = res;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};