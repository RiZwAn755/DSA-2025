// concept of 3d dp


// using recurrsion only 

int dj[3] = {-1 , 0 , 1};

int rec(int r , int cA , int cB , vector<vector<int>>&g)
{
    int n = g.size();
    
    // always write out of bounds cases
    if(cA <0 || cA >= n || cB < 0 || cB >= n) return -1e8 ;
    
    // base case
    if(r == n-1)
    {
        if(cA == cB) return g[n-1][cA];
        else return g[n-1][cB];
    }
    
    int maxi = -1e8 ;
    
    // exploring all possible combination of moves of alice and bob in one step 
    
    for(int x = 0 ; x < 3 ; x++)
    {
        for(int y =0; y< 3 ; y++)
        {
            if(cA == cB )
           {
               maxi = max( maxi , g[r][cA] + rec(r+1 , cA+dj[x] , cB+dj[y] , g));
           }
           else 
           {
              maxi = max(maxi , g[r][cA] + g[r][cB] + rec(r+1 , cA+dj[x] + cB+dj[y] , g));
           }
        }
    }
    
    return maxi ;
    
}

// TC = Alice will travel all row  , bob will also all row and both have 3 optoin at each step => 3^n + 3^n 
// SC  = auxialry stack space O(N);


// DP /

class Solution {
public:
    int dj[3] = {-1, 0, 1};

    int rec(int r, int cA, int cB, vector<vector<int>>& g, vector<vector<vector<int>>>& dp) {
        int n = g.size();
        int m = g[0].size();

        if (cA < 0 || cA >= m || cB < 0 || cB >= m) return -1e8;

        if (r == n - 1) {
            if (cA == cB) return dp[r][cA][cB] = g[r][cA];
            else return dp[r][cA][cB] = g[r][cA] + g[r][cB];
        }

        if (dp[r][cA][cB] != -1) return dp[r][cA][cB];

        int maxi = -1e8;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                int nextA = cA + dj[x];
                int nextB = cB + dj[y];
                int temp;
                if (cA == cB)
                    temp = g[r][cA] + rec(r + 1, nextA, nextB, g, dp);
                else
                    temp = g[r][cA] + g[r][cB] + rec(r + 1, nextA, nextB, g, dp);

                maxi = max(maxi, temp);
            }
        }

        return dp[r][cA][cB] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return rec(0, 0, m - 1, grid, dp);
    }
};
