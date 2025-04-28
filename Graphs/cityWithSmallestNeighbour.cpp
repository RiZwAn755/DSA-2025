// class Solution {
//     public:
//         int n, m;
//         vector<vector<pair<int, int>>> g;
//         vector<vector<int>> dist;
    
//         int findCity(int n, int m, vector<vector<int>>& e, int td) 
//         {
//             this->n = n;
//             this->m = m;
//             dist.assign(n, vector<int>(n, 1e8));
//             g.resize(n);
    
//             // making adjacency list
//             for (int i = 0; i < m; i++) {
//                 int u = e[i][0];
//                 int v = e[i][1];
//                 int wt = e[i][2];
    
//                 g[u].push_back({v, wt});
//                 g[v].push_back({u, wt});
//                 dist[u][v] = wt;
//                 dist[v][u] = wt;
//             }
    
//             for (int i = 0; i < n; i++) {
//                 dist[i][i] = 0;
//             }
    
//             // Floyd-Warshall algo
//             for (int via = 0; via < n; via++) {
//                 for (int i = 0; i < n; i++) {
//                     for (int j = 0; j < n; j++) {
//                         if (dist[i][via] + dist[via][j] < dist[i][j])
//                             dist[i][j] = dist[i][via] + dist[via][j];
//                     }
//                 }
//             }
    
//             // computing the minCity
//             int ans = -1, minReachable = 1e8;
    
//             for (int i = 0; i < n; i++) {
//                 int cnt = 0;
//                 for (int j = 0; j < n; j++) {
//                     if (dist[i][j] <= td) {
//                         cnt++;
//                     }
//                 }
    
//                 if (cnt <= minReachable) {
//                     minReachable = cnt;
//                     ans = i;
//                 }
//             }
    
//             return ans;
//         }
//     };