// class Solution {
//     public:
         
//          int dx[4] = { 0 , 0 , -1 , 1};
//          int dy[4] = {1 , -1 , 0 , 0};
//          vector<vector<int>>vis;
    
//         int ck(vector<vector<int>> image , int sr , int sc , int i  ,int j)
//         {
//               int n = image.size();
//               int m = image[0].size();
    
//               if(i < 0 || i >= n || j  < 0 || j >= m || image[sr][sc] != image[i][j])
//               {
//                 return 0;
//               }
    
//               return 1;
//         }
          
//           void dfs(vector<vector<int>> image , int i , int j , int color , vector<vector<int>>&ans, int sr , int sc)
//            {
//               int n = image.size();
//               int m = image[0].size();
              
//                 vis[i][j] = -2; // bcoz the elements are postive
//                 ans[i][j]  = color;
//                 for(int d =0 ; d < 4 ; d++)
//                 {
//                   int ni = i + dx[d];
//                   int nj = j + dy[d];
    
//                   if(ck(image, sr ,  sc ,ni , nj))
//                   {
//                     if(vis[ni][nj] == -1)
//                     {
//                         dfs(image , ni , nj , color , ans ,sr , sc);
//                     }
//                   }
//                 }
    
    
//            }
    
    
//         vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
//               int n = image.size();
//               int m = image[0].size();
    
//               vis.assign(n , vector<int>( m , -1));
//               vector<vector<int>>ans = image;
         
//               dfs(image , sr ,sc , color  , ans , sr , sc);
    
//               return ans;
    
              
            
//         }
//     };
