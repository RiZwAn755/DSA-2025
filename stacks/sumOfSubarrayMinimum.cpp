
                //    sum of subarray minimums
 
// problem states that you are given an array , find all possible subarrays of it and for each sub array find the minimum element in it 
// return the sum of minimum elements from each subarray

// ex: arr = [3 ,1, 2,4]
// possoble subarray

// 3      min -> 3                            1         min -> 1                   2       min -> 2              4           -> min 4
// 3 1     min -> 1                           1 2       min -> 1                   2 4      min -> 2 
// 3 1 2 4    min - >1                        1 2 4    min -> 1

// ans is sum of all minimums = 3 + 1 + 1 + 1+ 1+1+1 +2 +2 + 4      => 17 this is ans  if value is large return ans my modding with 1e9+7


// brute force we can use two loops



//   for(int i = 0;  i < n-1; i++)
//   {
//     int mini = a[i];
//     for(int j = i ; j < n-1; j++)
//     {
//         mini = min(mini , a[j]);
//     }

//     sum = (sum+mini)%(1e9+7);
//   }

//   return sum;



class Solution {
public:

    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n); // Initialize ans with n (default next smaller element position)
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Find next smaller element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top(); // Store index of next smaller element
            }

            st.push(i); // Push the current index onto the stack
        }

        return ans;
    }

    vector<int> psee(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1); // Initialize ans with -1 (default previous smaller element position)
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // Find previous smaller element
            while (!st.empty() && arr[st.top()] > arr[i]) { // here we dont have equality***
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top(); // Store index of previous smaller element
            }

            st.push(i); // Push the current index onto the stack
        }

        return ans;
    }

    const int mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        if (arr.empty()) return 0; // Handle edge case when array is empty

        vector<int> ns = nse(arr); // Next smaller element
        vector<int> ps = psee(arr); // Previous smaller element

        long long ans = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            // How many numbers after i where i is the minimum
            int Ns = ns[i] - i;
            // How many numbers before i where i is the minimum
            int Ps = i - ps[i];
            // Calculate the result using modulo
            ans = (ans +  (1LL * arr[i] * Ns * Ps) % mod) % mod;
        }

        return ans;
    }
};





