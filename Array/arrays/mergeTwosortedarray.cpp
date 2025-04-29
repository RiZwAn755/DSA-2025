
// problem : to merge two sorted array without extra space
class Solution {
    public:
        void merge(vector<int>& nums1, int n1, vector<int>& nums2, int n2) 
        {
            int i = n1-1; // last index of first array
            int j = n2-1; // last index of second array
            int k = n1+n2-1; // last index of merged array
    
    
            // nums2 ko khali kar rhe h
            // nums1 me hi nums2 ko merge kar rhe hai
            while(j >= 0)
            {
                if(i >=0 && nums1[i] > nums2[j])
                {
                    nums1[k--] = nums1[i--];
                }
                else
                {
                    nums1[k--] = nums2[j--];
                }
            }
    
           
        }
    };
