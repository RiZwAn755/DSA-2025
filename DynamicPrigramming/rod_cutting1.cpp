//  Given a rod of length n inches and an array price[], 
//  where price[i] denotes the value of a piece of length i.
//   Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Note: n = size of price, and price[] is 1-indexed array.
 
 
 int rec(int i , int n , vector<int> &p , int ans , vector<vector<int>>& dp)
  {
      
      if(n == 0)
      {
          return ans;
      }
      if(i > n || n < 0 )
      {
          return 0 ;
      }
      
      if(dp[i][n] != -1) return dp[i][n];
      
      // cut
      int cut =0;
      if(i <= n) cut = p[i-1] +  rec(i ,n-i , p ,ans,dp);
      // not cut 
      int noCut = rec(i+1 , n , p , ans ,dp);
      
       return dp[i][n] =  max( cut , noCut);     
  }
  
    int cutRod(vector<int> &p) 
    {
       
       int n = p.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1)); // i, n 
       return rec( 1 , n , p , 0 , dp);
    }

    TC: states* workPerState => n*n*1;
    state = dp[i][n] => #states = (#values i can take )*(#values n can take);
    workPerState = O(1) 

    TC = states*workPerState = O(N^2) ;