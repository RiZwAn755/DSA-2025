


// Problem : mark all Os by X that surrounded by Xs  
// Approach : mark all Os that are at boundaries visted , remaining will be surrounded , so convert them in X 




// class Solution {
//     public:
//          vector<vector<char>>g;
//          vector<vector<int>>vis;
//          int n , m ;
    
//          int dx[4] = {0 , 0 , 1 , -1};
//          int dy[4] = {-1 , +1 , 0 , 0};
    
//          int ck(int i ,int  j)
//          {
//             if(i <0 || i >= n || j < 0 || j >= m )
//             {
//                 return 0;
//             }
//             return 1;
//          }
//           void dfs1(int i ,int j)
//           {
//             vis[i][j] = 1;
//              for(int d = 0 ; d < 4 ; d++)
//              {
//                int ni = i + dx[d];
//                int nj = j + dy[d];
                
//                 if(ck(ni, nj) && !vis[ni][nj] && g[ni][nj] == 'O') 
//                 {
                   
//                     dfs1(ni , nj);
//                 }
//              }
            
//           }
       
    
//         void solve(vector<vector<char>>& board) 
//         {
//             n = board.size();
//              m = board[0].size();
//              g = board;
//              vis.assign(n , vector<int>(m , 0));
    
//             for(int i =0 ; i < m; i++)
//             {
//                 if(g[0][i] == 'O' && !vis[0][i])
//                 {
//                     dfs1(0 , i);
//                 }
//                  if(g[n-1][i] == 'O' && !vis[n-1][i])
//                 {
//                     dfs1(n-1 , i);
//                 }
               
//             }
//             for(int i =0 ; i < n; i++)
//             {
//                 if(g[i][0] == 'O' && !vis[i][0]){
//                     dfs1(i , 0);
//                 }
//                  if( g[i][m-1] == 'O' && !vis[i][m-1])
//                 {
//                   dfs1(i , m-1);
//                 }
//             }
    
//             for(int i =1 ; i < n-1 ;i++)
//             {
//                 for(int j =1 ; j < m-1 ; j++)
//                 {
//                     if(g[i][j] == 'O' &&  vis[i][j] != 1)
//                     {
//                        g[i][j] = 'X';
//                     }
//                 }
//             }
    
//               board = g;
//         }
//     };