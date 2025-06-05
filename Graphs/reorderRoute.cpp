// all nodes wanna go to node-0 if theres no path make them , return how many roads to be made  


// class Solution {
//     public:
//         vector<int>vis ;
//         vector<vector<pair<int ,int>>>g ;
//         int n , m ;
    
//         void dfs(int i, int& ans)
//         {
//             vis[i] = 1;
//             for(auto it : g[i])
//             {
//                if(!vis[it.first])
//                {
//                 if(it.second) // if theres no path make it
//                 {
//                     ans++;
//                 }
//                 dfs(it.first , ans);
//                }
//             }
//         }
//         int minReorder(int n, vector<vector<int>>& c)
//         {
//             // c[i][0] to c[i][1] ;
//             n = n , m = c.size();
//             g.resize(n);
//             vis.assign( n , 0);
//             for(int i = 0 ;i < c.size() ; i++)
//             {
//                 int x = c[i][0];
//                 int y = c[i][1];
//                 g[x].push_back({y , 1}); // there is path
//                 g[y].push_back({x , 0}); // theres no path
    
//             }
//              int ans = 0 ; 
            
//              dfs(0 , ans); 
//              return ans ;
//         }
//     };