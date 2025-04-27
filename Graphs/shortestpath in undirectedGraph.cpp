

// class Solution {
//     public:
//         int n, m;
//         vector<vector<pair<int, int>>> g;
//         vector<int> dist;
//         vector<int> parent;
    
//         vector<int> shortestPath(int n, int m, vector<vector<int>>& e) 
//         {
//             this->n = n;
//             this->m = m;
//             g.clear();
//             g.resize(n + 1);
//             dist.assign(n + 1, 1e9);
//             parent.assign(n + 1, -1);
    
//             for (int i = 0; i < e.size(); i++) 
//             {
//                 int u = e[i][0];
//                 int v = e[i][1];
//                 int wt = e[i][2];
    
//                 g[u].push_back({v, wt});
//                 g[v].push_back({u, wt});
//             }
    
//             priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//             dist[1] = 0;
//             pq.push({0, 1});
    
//             while (!pq.empty()) 
//             {
//                 int wt = pq.top().first;
//                 int node = pq.top().second;
//                 pq.pop();
    
//                 for (auto it : g[node]) 
//                 {
//                     int childnode = it.first;
//                     int childwt = it.second;
    
//                     if (dist[childnode] > wt + childwt) 
//                     {
//                         dist[childnode] = wt + childwt;
//                         pq.push({dist[childnode], childnode});
//                         parent[childnode] = node;
//                     }
//                 }
//             }
    
//             if (dist[n] == 1e9) 
//             {
//                 return {-1};
//             }
//             else 
//             {
//                 vector<int> path;
//                 int curr = n;
                
//                 while (curr != -1) 
//                 {
//                     path.push_back(curr);
//                     curr = parent[curr];
//                 }
                
//                 reverse(path.begin(), path.end());
    
//                 vector<int> ans;
//                 ans.push_back(dist[n]);
                
//                 for (int node : path) 
//                 {
//                     ans.push_back(node);
//                 }
                
//                 return ans; // ans contains final weight to reach node n from node 1 , and nex the path to reach 1 to n in minimum wt 
//             }
//         }
//     };