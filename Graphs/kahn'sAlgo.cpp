

// kahns algorithm ===> topological sort using bfs(with some tweak).

// approach => insert all node with indegree equal to zero in the queue

class Solution {
    public:
    vector<vector<int>>g;
    vector<int>vis;
    int n , m ;
    
    void dfs(int node , stack<int>& st)
    {
        
    }
    
      vector<int> topoSort(int V, vector<vector<int>>& edges) 
      {
          m = edges.size();
          n = V;
          vis.assign(n , 0);
          g.resize(n );
          vector<int>ans;
         vector<int>indeg( n , 0);
        
          for(int i =0 ; i < m; i++)
          {
              int x = edges[i][0];
              int y = edges[i][1];
              g[x].push_back(y);
              indeg[y]++;
          }
          
          queue<int>q;
          
          for(int i =0 ; i < n;i++)
          {
              if(indeg[i] == 0)
              {
                  q.push(i);
              }
          }
          
          
          while(!q.empty())
          {
              int node = q.front();
              q.pop();
              ans.push_back(node);
              for(auto it : g[node])
              {
                  indeg[it]--;
                  if(indeg[it] == 0)
                  {
                      q.push(it);
                  }
              }
              
              
          }
          
          return ans;
  
      }
  };

