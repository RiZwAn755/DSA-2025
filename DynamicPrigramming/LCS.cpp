

//  find longest common subsequence in two strings s1 and s2 


// approach1 :- recurrence + memoisation

rec(int i , int j , string& s , string& t , vector<vector<int>>& dp)
{
    if(i >= s.size() || j >= t.size()) return 0 ; 

     if(dp[i][j] != -1) return dp[i][j] ;

    if(s[i] == t[j])
    {
        return 1 + rec(i+1 , j+1 , s ,t , dp);
    }

    int a = rec(i+1 , j , s , t , dp) ;
    int b = rec(i ,j+1 , s, t , dp);

    return dp[i][j] =  max(a , b);
 }

//  Approach 2 :-  tabulation => reduce auxiliary stack space 
   
  int rec( string s , string t)
  {
      int n = s.size() ;
      int m = t.size() ;
vector<vector<int>>dp(s.size()+1 , vector<int>(t.size()+1 , -1));
 for(int i =0; i < s.size(); i++)
 {
     dp[i][0] = 0 ;
 }

 for(int i =0; i < m; i++)
 {
    dp[0][i] = 0 ;
 }



 for(int i =1; i <= n; i++)
 { 
    for(int j =1 ; j <= m; j++)
    {
        if(s[i-1] == t[j-1])
        {
           dp[i][j] = 1 + dp[i-1][j-1] ;
        }
        else{
             int a = dp[i-1][j];
             int b = dp[i][j-1];
             
             dp[i][j] = max(a , b) ;
        }
    }
 }

 return dp[n][m] ;

  }


  // Approach 3 :- Space Optimization

  int rec(string s , string t)
  {
    int n = s.size() ;
      int m = t.size() ;
vector<vector<int>> sprev(n+1) , curr(n+1);
 for(int i =0; i < s.size(); i++)
 {
     prev[i] = 0 ;
 }

 for(int i =1; i <= n; i++)
 { 
    for(int j =1 ; j <= m; j++)
    {
        if(s[i] == t[j])
        {
            curr[j]= 1 + prev[j-1] ;
        }
        else{
              curr[j] msx(pre[j] , curr[j-1]);
           
        }
    }
    rev = curr; 
  }

  return prev[n];
}

  

