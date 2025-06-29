 
 question : 
 
           a robot is at the top left corner of a grid and it wants to reach the bottom right corner 
           he can only move right or down 
           find the number of unique paths to reach the bottom right corner 

 
 int rec(int i , int j , int m , int n, vector<vector<int>>& dp )
    {
        if(i == m-1 && j == n-1)
        {
            return 1 ;
        }

        if(i< 0 || i>= m || j < 0 || j >= n)
        {
            return 0; 
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        return dp[i][j] =  rec(i+1 , j , m , n , dp) + rec(i , j+1 , m , n , dp) ;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m , vector<int>(n , -1));
        return rec(0 , 0 , m , n , dp);
    }

        TC : O(m*n) because we are visiting each cell once 
        SC : O(m*n) because we are using a 2d array to store the results 


        tabulation : 

        int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m , vector<int>(n , 0));
        dp[0][0] = 1;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }
                int up = 0 , left = 0 ;
                if(i > 0)
                {
                    up = dp[i-1][j];
                }
                if(j > 0)
                {
                    left = dp[i][j-1];
                }                                       

                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
    
        TC : O(m*n) because we are visiting each cell once 
        SC : O(m*n) because we are using a 2d array to store the results 





