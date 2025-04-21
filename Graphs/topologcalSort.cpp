// topological sort it only occurs in directed acyclic graph (DAG)

// (g[u] = v ) => path from u to v , i.e u occurs before v.
// so in topological sort we need to return the nodes in an order such that the always occurs before v 

// class Solution {
//     public:
//     vector<vector<int>>g;
//     vector<int>vis;
//     int n , m ;
    
//     void dfs(int node , stack<int>& st)
//     {
//         vis[node] =1 ;
//         for(auto it : g[node])
//         {
//             if(!vis[it])
//             {
//                 dfs(it , st);
//             }
//         }
//         st.push(node);
//     }
    
//       vector<int> topoSort(int V, vector<vector<int>>& edges) 
//       {
//           m = edges.size();
//           n = V;
//           vis.assign(n , 0);
//           g.resize(n );
//           for(int i =0 ; i < m; i++)
//           {
//               int x = edges[i][0];
//               int y = edges[i][1];
//               g[x].push_back(y);
//           }
          
//           stack<int>st;
//           for(int i = 0 ; i < n; i++)
//           {
//               if(!vis[i])
//               {
//                   dfs(i , st);
//               }
//           }
          
//           vector<int>ans;
//           while(!st.empty())
//           {
//               ans.push_back(st.top());
//               st.pop();
//           }
          
//           return ans;
//       }
//   };
