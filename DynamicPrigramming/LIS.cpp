

// # find longest increasing subsequence

// recurrsive + memoisation approach

int recur(int i , vector<int>nums , int prev_idx, vector<vector<int>>& dp)
{
    if(i >= arr.size()) return 0 ;
    
    int p = 0 ;

    if(dp[i][prev_idx+1] != -1) return dp[i][prev_idx+1];

    if(prev_idx == -1 || nums[i] > nums[prev_idx])
    {
        p = recur(i+1 , nums , i, dp);
    }

    int q = recur(i+1 , nums , prev_idx, dp);

    return dp[i][prev_idx+1] =  max(p , q);


}

int LIS(vector<int>nums )
{
    // here we took 2D dp, 
    // dp[i][prev_idx] , at index i , the prev_large element is at prev_idx ;
    // prev_idx's range we have taken nums.size()+1 , bcoz it goes from -1 to n-1 ;

    vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1 , -1));
    return recur(0 , nums , -1, dp);
}

// tabulation 

// rule: write base case

// write changing parameter in opposit fashion

// copy the rec


int LIS (int i , vector<int>& nums , int prev_idx)
{
    if(i >= nums.size()) return 0 ;

    for(int idx = n-1 ; idx >= 0; idx--)
    {
        for(int p = idx-1 ; p >= -1 ; p--)
        {
             int pp = 0 ;

            if(dp[i][prev_idx+1] != -1) return dp[i][prev_idx+1];

             if(prev_idx == -1 || nums[i] > nums[prev_idx])
              {
                    pp = dp[i+1][i];
               }

                 int q = dp[i+1][prev_idx];

                 dp[i][prev_idx+1] =  max(pp , q);
        }
    }

    return [0][-1+1];

}