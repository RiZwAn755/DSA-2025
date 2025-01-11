

// find the sum of (difference of max and min element) from each subarray

// ex: arr = [3 ,1, 2,4]
// possoble subarray

// 3      max-min -> 0                              1         max-min -> 0                   2       max-min -> 0               4            max-min  ->4
// 3 1     max-min -> 2                             1 2       max-min -> 1                   2 4      max-min -> 2 
// 3 1 2     max-min ->  2                          1 2 4    max-min -> 3
//3 1 2 4    max-min -> 3

// ans is sum of all minimums = 0 + 2 + 3 + 0 + 1 + 3 + 0 + 2 + 0   => 11 this is ans  if value is large return ans my modding with 1e9+7






// --------------------------------brute force---------------------------------------------------------------------

// for(int i =0 ; i < n; i++ )
// {     
//     int smallest = a[i] , largest = a[i];
//     for(int j = i+1 ; j < n; j++)  // j = i+1 bcoz if we take single element as subarray it will not afect answer bcoz its itself is max and min
//     {
//          largest = max(largest  , a[j]);
//          smallest = min(smallest , a[j]);  
//            sum += (largest - snmallest);        writing it inside the for loop bcoz adding each element will make new subarray       
//     }
//   
// }
// return sum ;



// ----------------------------------------optimization-----------------------------------------------------------

// we want subarray ranges (i.e maximum - minimum) for each sub-array 
// i.e  (maxof subarray1 - minof subarray1) + (maxofsubarray2 - minof subarray2) + ....... And so on....
// it finally comes out to be  (sum of subarray maximums - sum of subarray maximums)
// for solving it we need to know the problem sum of subarray minimum and similiarly we can find sum of subarray maximums 

 class Solution {
public:
    
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        stack<int>st;
        vector<int> minPrev(n,-1),minNext(n,n),maxPrev(n,-1),maxNext(n,n);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i]){st.pop();}
            if(!st.empty()){minPrev[i]=st.top();}
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>nums[i]){st.pop();}
            if(!st.empty()){minNext[i]=st.top();}
            st.push(i);
        }
        
         for(int i=0;i<n;i++)
         {
            while(!st.empty()&&nums[st.top()]<=nums[i]){st.pop();}
            if(!st.empty()){maxPrev[i]=st.top();}
            st.push(i);
         }
         while(!st.empty()){st.pop();}
         for(int i=n-1;i>=0;i--)
         {
            while(!st.empty()&&nums[st.top()]<nums[i]){st.pop();}
            if(!st.empty()){maxNext[i]=st.top();}
            st.push(i);
         }
        
        for(int i=0;i<n;i++)
        {
            long long leftMin=i-minPrev[i],rightMin=minNext[i]-i;
            long long leftMax=i-maxPrev[i],rightMax=maxNext[i]-i;
            sum+=(leftMax*rightMax-leftMin*rightMin)*nums[i];
            
        }
        return sum;
    }
};
