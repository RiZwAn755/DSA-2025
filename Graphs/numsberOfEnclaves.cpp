
 // problem : given a binary grid , 1 = island , 0 = water , find number of islnad from whuch you cant go off grid
// approach : dfs all boundry 1s from where you can go off the grid  , hence remaining not visitef once will be the ans;


class Solution {
    public:
          
          vector<vector<int>>g ;
          vector<vector<int>>vis;
          int n , m ;
    
          int dx[4] = {0 , 0 , -1 , 1};
          int dy[4] = {1 , -1 , 0 , 0};
    
           int ck(int i , int j)
           {
            if( i < 0 || i >= n || j < 0 || j >= m )
            {
                return 0 ;
            }
            return 1;
           }
    
           void dfs(int i , int j)
           {
            vis[i][j] = 1;
    
            for(int d = 0 ; d < 4 ; d++)
            {
                int ni = i + dx[d];
                int nj = j + dy[d]; 
    
                if(ck(ni , nj))
                {
                    if(!vis[ni][nj] && g[ni][nj]== 1)
                    {
                        dfs(ni , nj);
                    }
                }
            }
           }
    
    
    
    
        int numEnclaves(vector<vector<int>>& grid) 
        {
            n = grid.size();
            m = grid[0].size();
    
            g = grid;
            vis.assign(n , vector<int>(m , 0));
    
            for(int i =0 ; i <  m; i++)
            {
                if(g[0][i] == 1 && !vis[0][i]) dfs( 0 , i);
                if(g[n-1][i] == 1 && !vis[n-1][i]) dfs(n-1 , i);
            }
    
            for(int i =0 ; i <  n; i++)
            {
                if(g[i][0] == 1 && !vis[i][0]) dfs( i , 0);
                if(g[i][m-1] == 1 && !vis[i][m-1]) dfs(i , m-1);
            }
    
            int ans = 0 ;
    
            for(int i =0 ; i < n ; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(g[i][j] == 1 && !vis[i][j])
                    {
                        ans++;
                    }
                }
            }
    
            return ans;
        }
    };
