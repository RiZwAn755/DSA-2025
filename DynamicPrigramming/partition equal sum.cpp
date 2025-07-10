

// can we devide the arrray in two different subset/subsequence , such that both sum of both parts are equall

// Recurrsive code: (TLE)

     bool rec(int i ,int sum ,  vector<int>& arr , int t)
      {
          if(i >= arr.size()) return false;
          
          if(sum == t)
          {
              return true;
          }
          
          bool take = rec(i+1 , sum+arr[i], arr , t );
          bool skip = rec(i+1 , sum ,arr , t );
          
          return (take || skip);
      }
    bool equalPartition(vector<int>& arr)
    {
        int sum = 0 ; 
        for(int i =0; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        
        if(sum&1) return false; 
        
      
        int i =0; 
        return rec(i ,0 ,  arr , sum/2 );
        
    }


    // memoisation : (TLE)

     bool rec(int i, vector<int>& arr , int t , vector<vector<int>>& dp)
      {
          if(i >= arr.size() || t< 0) return false;
          
          if(t == 0)
          {
              return true;
          }
          
          if(dp[i][t] != 0 ) return dp[i][t] ; 
          
          bool take = rec(i+1 , arr , t-arr[i], dp);
          bool skip = rec(i+1 ,arr , t , dp);
          
          return dp[i][t] = (take || skip);
      }
    bool equalPartition(vector<int>& arr)
    {
        int sum = 0 ; 
        for(int i =0; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        
        if(sum&1) return false; 
        
       vector<vector<int>>dp(arr.size()+1 , vector<int>(sum/2 +1 , 0 ));
        int i =0; 
        return rec(i ,arr , sum/2 , dp );
        
    }

    // Tabulation : (Accepted)

    step1: declare dp array of same size dp[n][target] ;

    step2: take base case from recurrsion

    base case1: (if at any index if got our target to be zero return true) =>  for(int i =0; i < n ; i++) dp[i][0] = true ;
    base case2: if arr[0] is eqaull to target we will return true => dp[0][arr[0]] = true ;

    step3: form a nested loop (#states times)
    index = 0  , is handled (second base case) ,
    target = 0, handled (first test case).
    so both loop start from 1 to n-1 ,1 to target

    code : 

    bool equalPartition(vector<int>& arr)
{
    int n = arr.size();
    int sum = 0;
    for (int num : arr)
        sum += num;

    if (sum & 1)
        return false; // Odd sum cannot be partitioned equally

    int t = sum / 2;

    vector<vector<bool>> dp(n, vector<bool>(t + 1, false));

    // Base case
    for (int i = 0; i < n; i++)
        dp[i][0] = true; // sum = 0 is always possible

    if (arr[0] <= t)
        dp[0][arr[0]] = true;

    // Build the dp table
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            bool skip = dp[i - 1][j];
            bool take = false;
            if (j >= arr[i])
                take = dp[i - 1][j - arr[i]];

            dp[i][j] = skip || take;
        }
    }

    return dp[n - 1][t];
}

    

     
