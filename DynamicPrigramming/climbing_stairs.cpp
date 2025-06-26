// You are climbing a staircase. It takes n steps to reach the top. 
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


// ** important note : 
// 1. try to represent the problem in terms of index
//2. do all the stuff with that index according to the problem statement
//3. if question says find all ways you can sum all the stuff to that index
//4. if question says find min or max you can keep doing min or max to that index








Approach 1 : Memoization 


class Solution {
public:

 
   int rec(int n, vector<int>&dp )
   {
    if(n <= 2) return n;

       // faith
       if(dp[n] != -1) return dp[n];

 // 1 steps me phuch sakte h  + 2 steps me phuch sakte h , store the sum of both
            dp[n] =  rec(n-1 , dp) + rec(n-2 , dp) ;
       // expectaion 
       return dp[n] ;
   }

    int climbStairs(int n) 
    {

        vector<int>dp(n+1 , -1);
        return rec(n , dp);
       
    }
};

// Approach 2 : Tabulation 
// in this approach we use a bottom-up approach to solve the problem and we use a table to store the results of the subproblems
// so that we don't have to compute them again and again

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2 ; i <= n ; i++)   
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
