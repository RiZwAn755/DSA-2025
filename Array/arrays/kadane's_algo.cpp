
// problem kadane's algo is used for this problem : return the maximum of subarray sum,, i.e the subarray whose sum is max , return that sum
//example:
// Input: nums = [5,4,-1,7,8]
// Output: 23

// approach : lets make two vars sum = 0 and maxi = -INF, and iterate the nums and add each element to sum if sum > maxi , set maxi to sum ,
// if at any point sum becomes less than zero we set sum = 0 , (i.e hame kisi index k element ko add karne pr sum less ho rha h to ham wha se nya sum start krenge )

class Solution {
    public:
        int maxSubArray(vector<int>& nums) 
        {
            int n = nums.size();
            long long maxi = LONG_MIN; 
            long long sum = 0;
    
        for (int i = 0; i < n; i++) {
    
            sum += nums[i];
    
            if (sum > maxi) {
                maxi = sum;
            }
    
            if (sum < 0) 
            {                         // arr: 2 , -3 , 4 // sum_before : 2 , -1 , 3
                                                  //sum after: 2 , 0 , 4
                sum = 0;
            }
        }
        return maxi;
        }
    };

