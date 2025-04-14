 
 // problem : print pascal triangle's nth row
 // approach1 : use recurrsoin bcoz except 1st and 2nd row (these are 1 ,  1 1 ) , each rows ith char is sum of ith char and (i-1)th char of previous row.
 // approach2 : rth element of nth row is , nCr (obsevation)

// class Solution {
//     public:
    
//           vector<int>rec(int n )
//           {
//             if(n == 1)
//             {
//                 return {1};
//             }
//             else if(n == 2)
//             {
//                 return {1 ,1};
//             }
    
           
    
//             else 
//             {
//                 vector<int>prow = rec(n-1);
//                 vector<int>ans ;
//                 ans.push_back(1);
    
//                 for(int i =1 ; i < prow.size() ; i++)
//                 {
//                     ans.push_back(prow[i-1] + prow[i]);
//                 }
//                 ans.push_back(1);
//                 dp[n] = ans;
//                 return ans;
//             }
//           }
      
//         vector<vector<int>> generate(int numRoww)
//          {
//              vector<vector<int>> ans ;
//              int n = numRoww;
    
//              for(int i =1; i <= n; i++)
//              {
//                 vector<int>temp = rec(i);
//                 ans.push_back(temp);
//              }
//              return ans;
//          }
//     };