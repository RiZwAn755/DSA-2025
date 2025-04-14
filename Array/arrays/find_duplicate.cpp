//  problem : given an array of size n+1 , and having elements from 1 to n , and one element is repeated , return that element

// approach 1: fast and slow pointer known as flloyd algo or something  , 
// slow = nums[0] , fast = nums[0] ;

// **************use do while loop ************************************

// slow = nums[slow] and fast = nums[nums[fast]] , while slow !=  fast 


// class Solution {
//     public:
//         int findDuplicate(vector<int>& nums) 
//         {
//             int slow = nums[0];
//             int fast = nums[0];
    
//            do
//             {
//                 slow = nums[slow];
//                 fast = nums[nums[fast]];
//             } while(slow != fast);
    
//             fast = nums[0];
//             while(slow != fast)
//             {
//                 slow = nums[slow];
//                 fast = nums[fast];
//             }
    
//             return slow;
//         }
//     };

// Aprroach 2 : 


// vector<int> Solution::repeatedNumber(const vector<int> &arr) {
//     int n = arr.size();
 
//  int repeating = -1;

//  for (int i = 0; i < n; i++) {
//      int val = abs(arr[i]);
     
//      if (arr[val - 1] > 0) {
//          arr[val - 1] = -arr[val - 1];
//      }
//      else {
         
//          // ELement is repeating.
//          repeating = val;
//      }
//  }
 
//  int missing = -1;
 
//  // Value at missing value index
//  // will be positive.
//  for (int i=0; i<n; i++) {
//      if (arr[i] > 0) {
//          missing = i+1;
//          break;
//      }
//  }
 
//  return {repeating, missing};
// }
