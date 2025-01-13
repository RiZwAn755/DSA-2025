
// you are given an array and an integer window_size(k)
// you have to return an array containing maximum element in each window

//  ex:
//  arr = [1 ,3 ,-1 , -3 , 5 , 3 ,2 ,1 , 6] , k = 3 
//  ans = [3 , 3 , 5 ,5 ,5 , 3 ,6]

// ----------------------------brute force approach-------------------------------------------------------------
// run a loop and scan a window of size k i.e total n-k scans;
// its gonna be o(k*(n-k)) 

// ---------------------------------optimization----------------------------------------------------------------

// to solve it in one traversle , we can make a sliding window and we keep adding element next and delete  the element at 'L' i.e a dequeue
// so we need a data structure in which we can delete and add in back and front
// in order to get max we need to scan , but we cant do for each window ==> hence we use monotonic stack , store element in decreasing order
// when we need max or min in o(1) we must think about monotonic stack.

// so we will have deque<int>dq  , which stores {index} and when we have less than element in the dq , 
// and arr[i] is greater than  dq.front() , then we pop the dq while greater element not found or the dq is empty.else if the arr[i] is smaller 
// we just push it in dq.
// when i >= k-1 , we will push the front in result array




#include<bits/stdc++.h>
using namespace std;

vector<int>MaxSlidingWindow(vector<int>arr)
{
      int n = arr.size();
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than the current element from the back
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // Add the maximum element of the current window to the result
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
}

int main()
{
   int n , k; cin >> n >> k; 
   vector<int>arr(n);
   for(int i=0; i < n; i++) cin >> arr[i];
   vector<int>ans = MaxSlidingWindow(arr);
   for(int i =0; i < ans.size() ; i++) cout << ans[i] << " ";
   cout << endl;

}

