
*********************************************************************************************************************************

class Solution {
public:
    int rec(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (j < 0 || j >= n) return 1e5; // check first
        if (i == m-1) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];

        int dwn = grid[i][j] + rec(i+1, j, m, n, grid, dp);
        int ldiag = grid[i][j] + rec(i+1, j-1, m, n, grid, dp);
        int rdiag = grid[i][j] + rec(i+1, j+1, m, n, grid, dp);

        return dp[i][j] = min({dwn, ldiag, rdiag});
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 1e5;

        for (int j = 0; j < n; j++) {
            ans = min(ans, rec(0, j, m, n, grid, dp));
        }
        return ans;
    }
};





// Tabulation  : in this problem only tabulation will work , bcox recurrsive will have TC(N* 3^M) , DP(M*N) , Tabulation (m*n)

    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp = grid;

        for (int i = m-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int dwn = dp[i+1][j];
                int ldiag = (j > 0) ? dp[i+1][j-1] : 1e5;
                int rdiag = (j < n-1) ? dp[i+1][j+1] : 1e5;
                dp[i][j] += min({dwn, ldiag, rdiag});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }

