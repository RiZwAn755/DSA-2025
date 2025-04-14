
// problem : given an array which only contains 0,1 and 2 we need to sort them .
// approach1:  directly sort => nlogn
//approach2 : take three pointers i = 0 , j = 0 and k = n-1 , i for zeros , j  for 1s and k for 2s.
// agar j pr zero ata h to ham j ko ek step age badha denge
// agr j pr zero aya to use i se swap kar denge, aur i, j dono ko badhayenge.
// agr j pr 2 aa gya to k se swap kr denge , aur jo ko badhayneg aur k ko kam krenge


// code:
// class Solution {
//     public:
//         void sortColors(vector<int>& nums)
//          {
//                int n = nums.size();
    
//               int i = 0 , j = 0 , k = n-1 ;
    
//               while( j <= k )
//               {
//                 if(nums[j] == 0)
//                 {
//                     swap(nums[i] , nums[j]);
//                     i++;
//                     j++;
//                 }
    
//                 else if(nums[j] == 1)
//                 {
                  
//                     j++;
                   
//                 }
//               else 
//               {
//                 swap(nums[j] , nums[k]);
//                 k--;
//                 j++;
//               }
    
//               }
        
//          }
//     };

