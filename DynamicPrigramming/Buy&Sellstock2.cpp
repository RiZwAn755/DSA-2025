
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock.
// You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

    int recur(int i, vector<int>& p, bool buy, vector<vector<int>>& dp) {
        if (i >= p.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if (buy) {
            profit = max(-p[i] + recur(i + 1, p, false, dp),
                         recur(i + 1, p, true, dp));
        } else {
            profit = max(p[i] + recur(i + 1, p, true, dp),
                         recur(i + 1, p, false, dp));
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return recur(0, p, true, dp);
    }