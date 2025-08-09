//  Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
 
 
 bool rec(int i , int j , string& s , string& t,  vector<vector<int>>& dp)
    {
        // base case 
        // 1. string 1 gets exhausted 
        // 2. string 2 gets exhausted 

        // if both gets exhausted return true, else false;
        // s = "abc"
        // t = "abcdd*r"

        if(i >= s.size() && j >= t.size()) return true ; // both strings exhausted
        if(i >= s.size() && j <t.size()) { for(int p = j; p < t.size() ;p++) { if(t[p] != '*') return false; } return true ; } // s exhausted, => t ke saare baaki elements * hone chahiye
        if(i < s.size() && j >= t.size() ) {for(int p = i ; p < s.size() ;p++) { if(s[p] != '*') return false; } return true ; } // t exhausted => s ke saare baaki elements * hone chahiye

         if(dp[i][j] != -1) return dp[i][j] ;

        if(s[i] == t[j] || s[i] == '?' || t[j] == '?')
        {
            return dp[i][j] =  rec(i+1 , j+1 , s , t, dp);
        }
        else if(s[i] == '*' || t[j] == '*')
        {
            //  take not take pattern
            // kyuki may be hame '*' ko ek char se match krna ho , 2 se krna ho and so on....
            return dp[i][j] =  (rec(i+1 , j , s , t, dp) || rec(i , j+1 , s , t , dp) ); 
           
        }
        else
        {
            return dp[i][j] =  false;
        }

    }
    bool isMatch(string s, string t) 
    {
        vector<vector<int>>dp(s.size() , vector<int>(t.size() , -1));
        return rec(0 , 0 , s , t, dp) ;
    }