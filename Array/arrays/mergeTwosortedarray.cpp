
// problem : to merge two sorted array without extra space
// class Solution {
//     public:
//         void merge(vector<int>& nums1, int n1, vector<int>& nums2, int n2) 
//         {
//             int i = n1-1;
//             int j = n2-1;
//             int k = n1+n2-1;
    
    
//             // nums2 ko khali kar rhe h
    
//             while(j >= 0)
//             {
//                 if(i >=0 && nums1[i] > nums2[j])
//                 {
//                     nums1[k--] = nums1[i--];
//                 }
//                 else
//                 {
//                     nums1[k--] = nums2[j--];
//                 }
//             }
    
           
//         }
//     };