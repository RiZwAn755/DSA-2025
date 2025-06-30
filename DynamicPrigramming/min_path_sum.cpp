 int rec(int i , int j, vector<vector<int>>&g , int m , int n,vector<vector<int>>& dp   )
    { 
      if(i == m-1 && j == n-1)
      {
        return g[m-1][n-1];        
      }       
        
      if(i < 0 || i>= m || j < 0 || j >= n) return 1e5; 
      if(dp[i][j] != -1 ) return dp[i][j];
        
        int right = g[i][j] + rec(i+1 , j ,g ,  m ,n ,dp);
        int down = g[i][j] + rec(i , j+1 , g , m, n,dp);

        return dp[i][j] =  min(right , down);

    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m , vector<int>(n, -1));
        return rec(0,0,grid,m,n, dp);
    }

    TC : O(m*n);
    SC : O(m*n);


//Tabulation        

    int minPathSum(vector<vector<int>>& g) 
    {
        int m = g.size();
    int n = g[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = g[0][0];

    // First column
    for(int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + g[i][0];
    }

    // First row
    for(int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + g[0][j];
    }

    // Rest of the grid
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = g[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m-1][n-1];
    }                                   




