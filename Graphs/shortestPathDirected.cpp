

// find shortest path in a directed graph
// sssp => single source shortest path in a directed graph

// class Solution {
//     public:
    
//     int n , m ; 
//     vector<vector<pair<int ,int>>>g;
//     vector<int>vis;
//     vector<int>dist;
    
    

//     void dfs(int i , stack<int>& st) // for topo sort
//     {
//         vis[i] = 1;
//         for(auto it : g[i])
//         {
//             int childnode = it.first;
//             int wt = it.second ;
//             if(!vis[childnode])
//             {
//                 dfs(childnode , st);
//             }
//         }
//         st.push(i);
//     }
    // void dfs(int i , stack<int>& st) // for topo sort.
    // // we used toposort to ensure that the node on which we are currently have its parents correct distance already
    // {
    //     vis[i] = 1;
    //     for(auto it : g[i])
    //     {
    //         int childnode = it.first;
    //         int wt = it.second ;
    //         if(!vis[childnode])
    //         {
    //             dfs(childnode , st);
    //         }
    //     }
    //     st.push(i);
    // }

    
//       vector<int> shortestPath(int V, int E, vector<vector<int>>& e) 
//       {
//           n = V , m =E  ;
//           g.resize(n);
//           vis.assign(n , 0);
//           dist.assign(n , 1e9);
          
//           for(int i =0; i < m; i++)
//           {
             
//                   int u = e[i][0];
//                   int v = e[i][1];
//                   int wt = e[i][2];
//                   g[u].push_back({v , wt});
              
//           }
//           stack<int>st;
//           for(int i =0 ; i < n; i++)
//           {
//               if(!vis[i])
//               {
//                   dfs(i , st);
//               }
//           }
          
//           dist[0] = 0; // distance of source node
          
//           while(!st.empty())
//           {
//               int x = st.top();
//               st.pop();
              
//               for(auto it : g[x])
//               {
//                   int cnode = it.first;
//                   int wt  = it.second;
                  
//                   if(dist[x] + wt < dist[cnode]) // if dist of child node is smaller than, 
//                                                  // current dist of child then relax the node
//                   {
//                       dist[cnode] = dist[x] + wt ;
//                   }
//               }
//           }
          
//           for(int i =0 ; i < n; i++)
//           {
//               if(dist[i] == 1e9)
//               {
//                   dist[i] = -1;
//               }
//           }
          
//           return dist;
//       }
//   };
