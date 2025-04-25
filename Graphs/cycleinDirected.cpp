

// cycle detection in a dorected graph and how its different fromundirected graph

// in directed we just visited the nodes and if the child node was not visited by it we say it have cycle,
// but herein case of directed , suppose we have a node from where we have two branch , dfs goes in one directon marking all node ,
// now it comes back to the parent node now while traversing in second branch , if it find someone marked then we wont say it have cycle.

// why ????

// bcoz here we donot have cycle , we cant reach to parent node through it.

// solution :)

// like visited array , we can have on e more array which will be marked 1  when its included in any path , and while coming back 
// we set it back to zero  then if we find a node visited and its path[i] = 0 , then we say it have a cycle
// path[i] == 0 => not in same path else its in same path
// .







class Solution {
    public:
    int n , m ;
    vector<vector<int>>g;
    vector<int>vis;
    vector<int>recStack;
    
    bool dfs(int node)
    {
        vis[node] = 1 ;
        recStack[node] = 1;
        for(auto it : g[node])
        {
            if(!vis[it])
            {
                if(dfs(it))
                return true;
            }
             else if (recStack[it]) {
                  // Node is in the recursion stack i.e we found a node in same path that is visited => cycle
                  return true;
              }
            
            
        }
        recStack[node] = 0; 
        return false;
    }
    
    
      bool isCyclic(int V, vector<vector<int>> &e) {
          n = V;
          m = e.size();
          g.resize(n );
          vis.assign(n , 0);
          recStack.assign(n , 0);
          
          for(int i =0; i < m ;i++)
          {
             
                  int x = e[i][0];
                  int y = e[i][1];
                  g[x].push_back(y);
              
          }
          
          for(int i =0 ; i < n; i++)
          {
              if(!vis[i])
              {
                  if(dfs(i)) 
                  {
                      return true;
                  }
              }
          }
          
          return false;
      }
  };
