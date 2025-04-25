// a node is terminal node if it have zero out degree 
// a node is safe node if all paths from it leads to a terminal node 
// return the array containg all the safe nodes

// observation : 
// terminal node itself is a safe node
// anyone part of a cycle and nodes which lead to cycle cant be safe node

// code 

// class Solution {
//     public: 
//        int n , m;
//        vector<vector<int>>g;
//        vector<int>vis;
//        vector<int>pathVis;
        
    
//        // cycle detection
    
//        bool  dfs(int node , vector<int>& check)
//        {
//         vis[node] = 1;
//         pathVis[node] = 1;
    
//         for(auto it : g[node])
//         {
//             if(!vis[it])
//             {
//                 if(dfs(it ,check))
//                 {
//                     check[node] = 0; // cycle ka part hai 
//                      return true;
//                 }
               
//             }
//            else  if(pathVis[it]) // if node has been visited and it has to be visited on same path again 
//             {
//                 check[node] = 0;
//                 return true;
//             }
//         }
//         check[node] =1 ; // kyuki agr cycle hoga to to wo phle hi return ho jata , code yha phucha matlb ye safe node h 
//         pathVis[node] = 0;
//         return false;
//        }
    
//         vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
//         {
//             n = graph.size();
//             m = graph[0].size();
//             g = graph;
//             vis.assign( n , 0);
//             pathVis.assign(n, 0);
//         //    check.assign(n , 0);
//            vector<int>check(n , 0);
    
//             for(int i =0 ; i < n; i++)
//             {
//                 if(!vis[i])
//                 {
//                     dfs(i , check);
//                 }
//             }
         
//            vector<int>ans;
//             for(int i =0; i  < n; i++)
//             {
//                 if(check[i])
//                 {
//                     ans.push_back(i);
//                 }
//             }
    
//             return ans;
//         }
//     };