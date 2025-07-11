// Given an array arr of non-negative integers and an integer 
// target, the task is to count all subsets of the array whose sum is equal to the given target. 

 int rec(int i , vector<int>&arr , int t , vector<vector<int>>& dp)
    {
         
         
         if(i == arr.size())
         {
             if(t == 0)
             {
                 return 1 ; 
              }
               
                return 0 ;
         }
         
         if(dp[i][t] != -1) return dp[i][t] ;
        
       
        int take =0 ; 
        
        if(arr[i] <= t) take = rec(i+1 , arr , t-arr[i] ,dp ) ;
        
        int skip = rec(i+1 , arr ,t ,dp) ;
        
        return dp[i][t] =  take + skip ;
    }
    int perfectSum(vector<int>& arr, int target) 
    {
        
        vector<vector<int>>dp(arr.size() , vector<int>(target+1 , -1));
        int i =0;
        return  rec(i, arr , target , dp );
    }