question : you are given an array of integers, you need to find the maximum sum of non-consecutive subsequence elements.
example : [1,2,3,1]
output : 4

explanation : 
            in this example we can see that the maximum sum of non-consecutive elements is 4.
            we too 1 and 3 to get the maximum sum.

Approach :
          we will take an element wont take its next , move to i+2 
          else we skip the element and move to i+1
          we are following take not take basically 

code :

      
  int rec( int i , vector<int>&dp , vector<int>nums)
  {
      if(i >= nums.size())
      {
          return 0;
      }

      if(dp[i] != -1) return dp[i] ;
 
      int take = nums[i] + rec(i+2 , dp , nums);
      int skip = rec(i+1 , dp , nums);

      dp[i] = max(take , skip); 

      return dp[i]; 
  }
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
   vector<int>dp(n+1 , -1);

    return rec(0, dp , nums);


}                      


TC : O(n) => each index we are calling 2 function calls
SC : O(n) + O(n) => dp array + O(n) recursion stack



int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int>dp(nums.size() , 0);
    int n = nums.size();
    dp[0] = nums[0] ; 
    int neg = 0 ; 

   for(int i = 1 ; i  < n; i++)
   {
    if(i > 1)
        int take = nums[i] + dp[i-2];
    else 
     int take = nums[i] + neg;
        int skip = dp[i-1];

        dp[i] = max(take , skip);
   }

      return dp[n-1];
} 


// space optimization :
 we always need only 2 values , so we can use 2 variables to store the values of the previous 2 indices.
 TC : O(n)
 SC : O(1)

 int prev2 = 0 ; 
 int prev = nums[0] ; 
 
 for(int i = 1 ; i < n ; i++)
 {
    int take = nums[i] + prev2;
    int skip = prev;
    int curr = max(take , skip);
    prev2 = prev;
    prev = curr;
 }
 // we have reached out of loop means we have reached n , we have to return the value of n-1 , so we return prev
 return prev;











