// Given an integer array coins[ ] representing different denominations of currency and an integer sum,
//  find the number of ways you can make sum by using different combinations from coins[ ]. 
// Note: Assume that you have an infinite supply of each type of coin 

int rec(int i , vector<int>& coins , int t, vector<vector<int>>& dp)
     {
          
          
         if(t == 0)
         {
             return 1 ;
         }
         
         if(i >= coins.size()) return 0 ; 
         
         if(dp[i][t] != -1) return dp[i][t] ; 
         
         int take = 0 ;
         
         if(coins[i] <= t) take =  rec(i , coins , t-coins[i] ,dp);
         
         int skip = rec(i+1 , coins ,t , dp);
         
         return dp[i][t] = take + skip ;
         
     }
     
    int count(vector<int>& coins, int sum) 
    {
       vector<vector<int>>dp(coins.size() , vector<int>(1e3+1 , -1));
        return rec(0 , coins , sum, dp);
    }