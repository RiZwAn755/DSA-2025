
// class Solution {
//     public:
//     bool ls(vector<int>nums ,  int x)
//     {
//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             if(nums[i] == x)
//             {
//                 return true;
                
//             }
           
//         }
//          return false;
//     }
    
    
//         int longestConsecutive(vector<int>& nums) 
//         {
//             int n = nums.size();
//             int ans = 1;
//             if(n == 0) return 0;
    
            // O(N^2)
            // for(int i =0 ; i < n; i++)
            // {      int cnt =0 ;
            //     int x = nums[i];
            //     while(ls(nums , x))
            //     {
            //         cnt++;
            //         ans = max(cnt , ans);
            //         x++;
    
            //     }
            // }


            // O(N)
    
    //         sort(nums.begin() , nums.end());
    //         int  cnt =  0 , lans = -1e6 ;
    //         for(int i =0 ; i < n; i++)
    //         {
    //             if(nums[i]-1 == lans)
    //             {
    //                 lans = nums[i];
    //                 cnt++;
    //                 // ans = max(ans , lans);
    //             }
    //             else if(lans != nums[i])
    //             {
    //                 cnt = 1; // making fresh start
    //                 lans = nums[i];
    //             }
    
    //             ans = max(ans , cnt);
                
               
    //         }
    //         return (ans);
    //     }
    // };