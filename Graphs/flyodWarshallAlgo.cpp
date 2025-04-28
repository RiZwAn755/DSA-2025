

// shortest path for all pair ==> multi source sortest path algorithm also helps in detecting neg cycles


// go via every vertex through each vertex and get the ans
// its a dp solution

// here we create a cost matrix :
// costMatrix(i , j) = cost from moving i to j ;


// code ::  

class Solution {
    public:
      void floydWarshall(vector<vector<int>> &dist) 
      {
          
      int n = dist.size();
   
     // already cost matrix given in n*n matrix having n nodes
     // go to all node through all node
     
     for(int via = 0; via < n; via++)
     {
     for(int i =0; i < n; i++)
     {
         for(int j =0 ; j < n; j++)
         {   
             if(dist[i][via] != 1e8 && dist[via][j] != 1e8)
             dist[i][j] = min(dist[i][j]  , dist[i][via]+dist[via][j]);
         }
     }
     
     }
     
  //   how to detect neg cycle 
  
  // if dist[i][j] < 0 ==> neg cycle
      // for(int i = 0 ; i < n; i++)
      // {
      //     if(dist[i][i] < 0)
      //     {
              //  return {-1};
      //     }
      // }
          
      }
  };