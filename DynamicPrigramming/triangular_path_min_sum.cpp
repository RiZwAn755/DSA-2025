int rec(int i , int j , int m , vector<vector<int>>&grid , vector<vector<int>>&dp)
  {
    if(i == m-1 && j < grid[m-1].size())
    {
        return dp[m-1][j] = grid[m-1][j];
    }

    if(i < 0 || i >= m || j < 0 || j >= grid[i].size())
    {
        return 1e8 ;
    }

    if( j>= 0 && j < grid[i].size() && dp[i][j] != -1) return dp[i][j];

    int down = grid[i][j] + rec(i+1 , j , m , grid, dp);
    int diag = grid[i][j] + rec(i+1 , j+1 , m , grid, dp);

    return dp[i][j] = min(down , diag);
  }
    int minimumTotal(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[m-1].size();
          vector<vector<int>>dp(m , vector<int>(n , -1));
      return   rec(0 ,0 , m , grid , dp);
    }