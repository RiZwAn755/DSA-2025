    question : Theres a from on first step and frog can jump to stair[i+1] or stair[i+2] at a time
    energy used to jump to stair[j] from stair[i] is abs(stair[j-1] - stair[i-1])
    find the minimum energy frog can use to reach the top

    Approach 1 : Memoization

    int rec(int n, vector<int> &h , vector<int>&dp) {
    if (n == 0) return 0;
    if (n == 1) return abs(h[1] - h[0]);
          
          if(dp[n]!= -1) return dp[n];

    return dp[n] =  min(
    //  dp[n]= min (1 step chalner ka result , 2 step chalner ka result)
        rec(n - 1, h ,dp) + abs(h[n] - h[n - 1]),
        rec(n - 2, h ,dp) + abs(h[n] - h[n - 2])
    );
}

Approach 2 : Tabulation
    
int frogJump(int n, vector<int> &h) 
{
    vector<int>dp(n+1 , -1);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2 ; i < n ; i++)
    {
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]) , dp[i-2] + abs(h[i] - h[i-2]));
    }
    return dp[n-1 ];
}
