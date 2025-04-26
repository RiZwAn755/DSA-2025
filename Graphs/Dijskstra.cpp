
// dijkstra algorithm => used for sssp for undirected or directed or weighted or unweighted graph

// three  mothods to implement Dijkstra Algo =>
// 1. priority queue (MIN heap)
// 2.  queue
// 3. set (bcoz set stores every thing in ascending order and we also use set bcoz we can erase a node from set if we find better way to reach here)


// doesnt work in a cycle with negative weight or graph having negative weight => bcoz dijkstra will fall in infinite loop 

// --------------------------------- priority queue method --------------------------------------------- 

// we use min heap priority queue <dist , node> .

// class Solution {
//     public:
//         vector<vector<pair<int,int>>> g;
//         vector<int> dist;
//         int n , m ;
    
//         vector<int> dijkstra(int V, vector<vector<int>> &e, int src) 
//         {
//             n = V;
//             m = e.size();
//             dist.assign(n, 1e9); // Sc O(N)
//             g.clear();
//             g.resize(n);
    
//             for(int i = 0; i < m; i++)
//             {
//                 int u = e[i][0];
//                 int v = e[i][1];
//                 int wt = e[i][2];
//                 g[u].push_back({v, wt});
//                 g[v].push_back({u , wt});
//             }
    
//         //   SC  O(n);
//             priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//             dist[src] = 0;
//             pq.push({0, src});
    
    
//     // T.C   mlog(N)
//             while(!pq.empty())
//             {
//                 auto x = pq.top();
//                 pq.pop();
//                 int wt = x.first;
//                 int node = x.second;
    
//                 for(auto it : g[node])
//                 {
//                     int adjNode = it.first;
//                     int edgeWeight = it.second;
    
//                     if(dist[adjNode] > dist[node] + edgeWeight)
//                     {
//                         dist[adjNode] = dist[node] + edgeWeight;
//                         pq.push({dist[adjNode], adjNode});
//                     }
//                 }
//             }
    
//             return dist;
//         }
//     };
    

// -------------------------- using set data structure ---------------------------------- 

// class Solution {
//     public:
//         vector<vector<pair<int,int>>> g;
//         vector<int> dist;
//         int n , m ;
    
//         vector<int> dijkstra(int V, vector<vector<int>> &e, int src) 
//         {
//             n = V;
//             m = e.size();
//             dist.assign(n, 1e9); // Sc O(N)
//             g.clear();
//             g.resize(n);
    
//             for(int i = 0; i < m; i++)
//             {
//                 int u = e[i][0];
//                 int v = e[i][1];
//                 int wt = e[i][2];
//                 g[u].push_back({v, wt});
//                 g[v].push_back({u , wt});
//             }
//             set<pair<int,int>>st;
//             dist[src] = 0 ;
//             st.insert({0 , src});
            
//             while(st.size())
//             {
//                 auto it = st.begin();
                
//                 auto x = *it;
//                 st.erase(x);
//                 int distt = x.first;
//                 int node = x.second;
                
//                 for(auto child : g[node])
//                 {
//                     int childnode = child.first;
//                     int childwt = child.second;
                    
//                     if(dist[childnode] > distt + childwt)
//                     {
//                         dist[childnode] = distt + childwt;
//                         int oo = dist[childnode];
//                         st.insert({oo , childnode});
//                     }
//                 }
//             }
            
//             return dist;
//         }
//     };
