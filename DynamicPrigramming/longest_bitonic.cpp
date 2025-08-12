// bitonic means it may first increase then it may decrease 
// ex : 1, 2, 4, 10, 2, 1, 0
// ex: 1,2,3,4,5 ;
// ex: 5 4 3 2 1;

// Approach :  bitonic array => increasing then decreasing (from right)
                                 +
                            //    increasing then decreasing from(left)
                            
        //   so we can find LIS from both side 
        
        // ans = max(LIS(i){left} + LIS(i){right})-1;  => -1 bcoz one ele\ment is count in both 

        vector<int> LIS( vector<int>& nums){

            int n = nums.size();
            vector<int>dp(nums.size() ,1);

          

            for(int i = 0 ; i < n; i++)
            {
                  int maxi = 1 ; 
                for(int j = 0; j < i ;j++)
                {
                    if(nums[i] > nums[j] &&dp[i] < dp[j]+1){
                        dp[i] = max(dp[i],  dp[j]+1);
                    }
                    
                }

                maxi = max(dp[i], maxi);
                dp[i] = maxi;
            }

            return dp ;
        }


    int LongestBitonicSequence(int n, vector<int> &v) {
        // code here
         vector<int>lLIS = LIS(v);
            reverse(v.begin() , v.end());
            vector<int>rLIS = LIS(v);
            reverse(rLIS.begin(), rLIS.end());
            
            // for(int i =0; i < n; i++){
            //     cout << rLIS[i]<<" ";
            // }
            // cout << endl;

            int ans = 0;
            
            if( *max_element(rLIS.begin() , rLIS.end()) == 1 || *max_element(lLIS.begin() , lLIS.end() ) == 1 ) return 0 ;

            for(int i =0; i < n; i++)
            {
                if(lLIS[i] != 1 && rLIS[i] != 1)
                 ans = max(ans , (lLIS[i]+rLIS[i])-1);
            }

            return ans ;
    }