 
 question : 
 
           a robot is at the top left corner of a grid and it wants to reach the bottom right corner 
           he can only move right or down 
           find the number of unique paths to reach the bottom right corner 
           if(g[i][j] == 1) then the cell is an obstacle and the robot cannot pass through it 



 int rec(int i , int j , int m , int n , vector<vector<int>>g , vector<vector<int>>&dp)
     {
        if(g[m-1][n-1] != 1 &&  (i == m-1 && j == n-1))
        {
            return 1;
        }

        if(i < 0 || i >= m || j < 0 || j >= n || g[i][j] == 1)
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        return dp[i][j] = rec(i+1 , j , m , n , g, dp) + rec(i , j+1 , m , n ,g , dp);
     }
    int uniquePathsWithObstacles(vector<vector<int>>&g) 
    {
        int m = g.size();
        int n= g[0].size();
        vector<vector<int>>dp(m ,vector<int>(n, -1));
       
        return rec(0 ,0 , m , n ,g , dp);
    }

    TC : O(m*n) because we are visiting each cell once 
    SC : O(m*n) because we are using a 2d array to store the results 
    