
// given a vector of vectors where each vector contains two elements startin and ending 
// task is to merge the intervals that are overlapping

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Appproach : make a vector<int>last , and start iterating on given vector of vector from i = 1 to less than n.
// if(last[1] > v[i][0]) => last[1] = v[i][0];
//   ans.push_back(last[0] , last[1]);
// else  ans.push_back({v[i]});
// return ans;


// code:

// class Solution {
//     public:
//         vector<vector<int>> merge(vector<vector<int>>& intervals) 
//         {        
            
//             sort(intervals.begin(), intervals.end());
    
//             vector<vector<int>> merged;
//             merged.push_back(intervals[0]); 
    
          
//             for (int i = 1; i < intervals.size(); i++) {
//                 vector<int>& last = merged.back();
                
//                 if (intervals[i][0] <= last[1]) {
                    
//                     last[1] = max(last[1], intervals[i][1]);
//                 } else {
                    
//                     merged.push_back(intervals[i]);
//                 }
//             }
    
//             return merged;
//         }
//     };
    