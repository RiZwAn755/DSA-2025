
// Given a set of items , each with a weight and a value, represented by the array wt and val respectively.
//  Also, a knapsack with a weight limit capacity.
// The task  is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times. 

// Input: val = [1, 1], wt = [2, 1], capacity = 3
// Output: 3
// Explanation: The optimal choice is to pick the 2nd element 3 times


 
    int rec(int i , vector<int>& val , vector<int>& wt , int c ,vector<vector<int>>& dp)
    {
        if(i >= val.size() || c < 0)
        {
            return 0;
        }
        
      
        
        if( dp[i][c] != -1) return dp[i][c] ;
        
        int take = 0 ; 
        
        if(wt[i] <= c) take = val[i] + rec(i , val , wt , c-wt[i] ,  dp);
        int skip = rec(i+1 , val , wt , c ,dp) ;
        
        return dp[i][c] =  max(take , skip);
        
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int c) 
    {
        vector<vector<int>>dp(val.size()+1 , vector<int>(c+1 , -1));
        
        return rec(0 , val , wt , c , dp);
    }