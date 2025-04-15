
//  leetcode matrix 01 
// need to be optimized 

// class Solution {
//     public:
        
//         vector<vector<int>>g;
    
//         int n , m ;
    
//         int ck(int i , int j)
//         {
//             if(i < 0 || i >= n || j < 0 || j>= m )
//             {
//                 return 0;
//             }
    
//             return 1;
//         }
    
//         int dx[4] = {1 ,0 , -1 ,0};
//         int dy[4] = {0 ,-1 , 0,1};
    
//         int bfs(int i , int j )
//         {
    
//                     vector<vector<int>> vis(n, vector<int>(m, 0));
//             vector<vector<int>> dist(n, vector<int>(m, 1e4));
    
//             vis[i][j] = 1;
//             dist[i][j] = 0;
//             queue<pair<int, int>>q;
//             q.push({i , j});
    
//             while(!q.empty())
//             {
//                 auto x = q.front();
//                 q.pop();
//                 for(int d = 0 ; d < 4 ; d++)
//                 {
//                     int ni = x.first + dx[d];
//                     int nj = x.second + dy[d];
    
//                     if(ck(ni , nj))
//                     {
//                        if(!vis[ni][nj])
//                        {
//                         dist[ni][nj] =  dist[x.first][x.second] + 1;
//                          vis[ni][nj] = 1;
    
//                          if(g[ni][nj] == 0)
//                          {                         
//                             return dist[ni][nj] ;
//                          }                  
                              
//                             q.push({ni, nj});                      
//                        }
//                     }
//                 }
//             }
//             return -1;
//         }
    
//         vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
//         {
//             g = mat;
//             n = g.size();
//             m = g[0].size();
           
//             vector<vector<int>>ans(n , vector<int>(m , 0));
    
//             for(int i =0;  i < n; i++)
//             {
//                 for(int j = 0 ; j < m; j++)
//                 {
//                     if(g[i][j] == 1)
//                     {
//                         int p = bfs(i , j);
//                         ans[i][j] = p;
//                     }
//                 }
//             }
            
//             return ans;
            
//         }
//     };