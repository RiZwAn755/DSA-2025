//  buy and sell stocks atmost 2 transactions allowed 
 

 int recur(int i , vector<int>& p , int cap , int buy , vector<vector<vector<int>>>& dp)
     {
        if(cap <= 0) return 0 ;
        if(i >= p.size()) return 0;
       
       if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        if(buy)
        {
            int Buy = -p[i] + recur(i+1 , p , cap , 0 , dp); // cap is not decreased bcoz 1 transacrtion = (1buy + 1 sell)
            int noBuy = recur(i+1 , p , cap , 1 ,dp);
            return dp[i][buy][cap] =  max(Buy, noBuy);
        }
        else
        {
            int sell = p[i] + recur(i+1 , p , cap-1 ,1,dp);
            int noSell = recur(i+1 , p , cap ,0 ,dp );
            return dp[i][buy][cap] = max(sell , noSell);
        }
     }
    int maxProfit(vector<int>& p) {
        
        vector<vector<vector<int>>>dp(p.size() , vector<vector<int>>(3 , vector<int>(3 , -1)));

        return recur(0 , p , 2 , 1 ,dp);
    }