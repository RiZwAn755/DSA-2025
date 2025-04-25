
// // need to find # distinct islands 

// class Solution {
//     public:
        
//         vector<vector<int>>g ; 
//         vector<vector<int>>vis;
//         int n , m ;
//         int dx[4] = { 0 , 0 , -1  , 1};
//         int dy[4] = {1 , -1 ,0 , 0 };
        
//         int ck(int i , int j)
//         {
//             if( i < 0 || i >= n || j < 0 || j >= m )
//             {
//                 return 0;
//             }
            
//             return 1;
//         }
        
//         void dfs(int i , int j , int i0 , int j0 , vector<pair<int , int>> & v)
//         {
//             vis[i][j] = 1;
//             v.push_back({i-i0 , j-j0}); // to store the shape
//             for(int d =0 ; d < 4 ; d++)
//             {
//                 int ni  = i + dx[d];
//                 int nj = j + dy[d];
                
//                 if(ck(ni , nj ) && !vis[ni][nj] && g[ni][nj] == 1)
//                 {
//                     dfs(ni , nj , i0 , j0 , v);
//                 }
//             }
//         }
    
//       int countDistinctIslands(vector<vector<int>>& grid) 
//       {
//           g = grid;
//           n = grid.size();
//           m = grid[0].size();
          
//           vis.assign(n , vector<int>( m , 0));
//           set<vector<pair<int ,int>>>st;
          
//           for(int i =0 ; i < n; i++)
//           {
//               for(int j =0 ; j < m; j++)
//               {
//                   vector<pair<int , int>>v;
//                   if(g[i][j] == 1 && !vis[i][j])
//                   {
//                       dfs(i , j , i , j , v);
//                         st.insert(v);
//                   }
                
//               }
//           }
          
//           return st.size();
//       }
//   };
  
