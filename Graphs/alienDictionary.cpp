// class Solution {
//     public:
//       vector<vector<int>> g;
//       vector<int> vis;
//       vector<int> indeg;
      
//       string findOrder(vector<string> &w) {
//           int n = w.size();
          
//           set<int> st;
//           for(int i = 0; i < n; i++) {
//               for(int j = 0; j < w[i].size(); j++) {
//                   st.insert(w[i][j] - 'a'); // fixed: set.insert -> st.insert
//               }
//           }
          
//           int p = st.size();
//           g.resize(26); // always 26 for 'a' to 'z'
//           vis.assign(26, 0);
//           indeg.assign(26, 0);
          
//           for(int i = 0; i < n - 1; i++) {
//               int len = min(w[i].size(), w[i+1].size());
//               int j = 0;
//               for(j = 0; j < len; j++) {
//                   if(w[i][j] != w[i+1][j]) {
//                       g[w[i][j] - 'a'].push_back(w[i+1][j] - 'a');
//                       indeg[w[i+1][j] - 'a']++;
//                       break;
//                   }
//               }
//               // Edge case: like ["abc", "ab"]
//               if(j == len && w[i].size() > w[i+1].size()) {
//                   return "";
//               }
//           }
          
//           queue<int> q;
//           for(int i = 0; i < 26; i++) {
//               if(st.count(i) && indeg[i] == 0) {
//                   q.push(i);
//               }
//           }
  
//           string ans = "";
//           while(!q.empty()) {
//               int x = q.front();
//               q.pop();
//               ans.push_back(x + 'a');
//               for(auto it : g[x]) {
//                   indeg[it]--;
//                   if(indeg[it] == 0) {
//                       q.push(it);
//                   }
//               }
//           }
          
//           if(ans.size() < st.size()) {
//               return "";
//           } else {
//               return ans;
//           }
//       }
//   };
  