

// again a algo which helps us to find shortest path .
// dijkstra fails when graph has neg edges , or negative cycle ==> tle
// bellmanford helps here also and gives the shortest path of all nodes from a sorce.
// ************************ ONLY APPLICABLE IN DIRECTED GRAPHS  **************
// for undirected we need to add edges of same wt in both direction.

// in bellmanford it tells us that theres a neg cycle

// ********************* statement of bellmanford ************************ 

// REALX ALL EDGES N-1 TIMES SEQUENTIALLY (N = # of nodes).
// edges can be in any order 
// why exactly N-1 relaxation  ????? bcoz we will compute the distance from all remaining node to it and then find the minimum  distance 

// ==> A shortest path between two vertices can have at most (V – 1) edges. It is not possible to have a simple path with more than (V – 1) edges 
// (otherwise it would form a cycle).
//  Therefore, repeating the relaxation process (V – 1) times ensures that all possible paths between source and any other node have been covered.


// we will make n-1 iteration to relax each edge n-1 times
// how we detect the neg cycle  
// ==>  on nth relaxation if distance array gets updated ==> theres neg cycle


// time comlexity => O(V*E)
// space complexity => O(N)


// code ::

// class Solution {
//     public:
    
  
//     vector<int>dist;
//     int n , m ; 
    
//       vector<int> bellmanFord(int V, vector<vector<int>>& e, int src) 
//       {
//          n = V; 
//          m = e.size();
         
//          dist.assign(n , 1e8);
     
//         dist[src] = 0;  // making the sorce dist to be zero
         
//          for(int i =0 ; i < n-1 ; i++)
//          {
//              for(int j = 0 ; j < m; j++)
//              {
//                  if(dist[e[j][0]] != 1e8 &&  dist[e[j][1]] > dist[e[j][0]] + e[j][2])
//                  {
//                      dist[e[j][1]] = dist[e[j][0]] + e[j][2];
//                  }
//              }
//          }
         
//       //   nth relaxation to check neg cycle 
      
//              for(int j =0 ; j < m; j++)
//              {
//                 if(dist[e[j][0]]!= 1e8 &&  dist[e[j][1]] > dist[e[j][0]] + e[j][2])
//                  {
//                      return {-1}; // neg cycle detected
//                  }
//               }
         
//          return dist;
//       }
//   };
