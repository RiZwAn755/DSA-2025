// given an array of integers, we need to put signs in fron of them to make the sum equal to target

// Approach : Like simple take , not take problem 

// **************************************************************************************************************
// ********** catch when we use dp[i][t] here t can be negative for sum values so we use offset as sum of array , to make it positive always**************
// **************************************************************************************************************


int rec(int i, vector<int>& nums, int t, vector<vector<int>>& dp, int x)
    {
        if (i == nums.size())
        {
            return t == 0;
        }
        
        if (t + x < 0 || t + x > 2 * x) return 0;
        if (dp[i][t + x] != -1) return dp[i][t + x];

        int plus = rec(i + 1, nums, t - nums[i], dp, x);
        int neg  = rec(i + 1, nums, t + nums[i], dp, x);

        return dp[i][t + x] = plus + neg;
    }

    int findTargetSumWays(vector<int>& nums, int t)
    {
        int x = 0;
        for (int num : nums) x += num;

        if (abs(t) > x) return 0;

        vector<vector<int>> dp(nums.size()+1, vector<int>((2 * x) + 1, -1));

        return rec(0, nums, t, dp, x);
    }