// question : given a array return true if any subsequense sum is k 


#include <bits/stdc++.h> 
  bool rec(int i , int sum , int t ,vector<int>&v , vector<vector<bool>>&dp)
   {

       if(sum == t)
      {
         return true;
      }

    if( i >= v.size() || sum > t) return false ;

    if(dp[i][sum] != false) return dp[i][sum] ;

     
       
      return dp[i][sum] =   rec(i+1 , sum+v[i] , t , v , dp) || rec(i+1 , sum , t , v, dp );

   }
bool subsetSumToK(int n, int k, vector<int> &arr) {

   vector<vector<bool>>dp( n+1, vector<bool>(k+1 , false));
   
   return  rec(0 , 0 , k , arr, dp);
   
    
}