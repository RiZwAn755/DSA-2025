// problem : given an array of stocks we have to find an stock and when to sell it in future so that we can have max profit
// return that max profit.

// approach 1 : run two loops i from 0 to less than n, and j from i+1 to less than n.  => o(n^2)

// approach 2 : run a loop and keep trak of max_profit and current profit


// code:

// class Solution {
// public:
//     int maxProfit(vector<int>& p)
//     {

        //---------------- O(n^2)-------------- ---
         // int n = p.size() , ck = 0 , ans = -1e4;
        //  for( int i =0; i < n; i++)
        //  {
        //     for(int j = i+1 ; j < n; j++)
        //     {
        //         ans = max(ans , p[j]-p[i]);
        //     }
        //  }
        //  if(ans < 0) return 0;
        //  return ans;



        // approach 2:

        //   int n = p.size() , ans = 0 , lowest_prev_stock = p[0];       
          
        //   for(int i = 1 ; i <n ; i++)
        //   {
        //           ans = max(ans , p[i]-lowest_prev_stock );
        //           lowest_prev_stock = min(lowest_prev_stock  , p[i]);         
        //   }

        //   return ans;
    // }

// };