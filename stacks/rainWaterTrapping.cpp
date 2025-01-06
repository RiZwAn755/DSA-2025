

// rain water trapping , here we are given with heights array where h[i] = height of ith building
// we have to tell how many unit water can be stored between buildings


// here we can observe that the amount of water that can be stored over a building is equall to 
// min of height of building which is tallest at its left and bulding which is tallest at its right minus the hieght of the current building4

#include<bits10_1.h>/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) 
    {
        int n = h.size();
        vector<int>pfm(n);
        vector<int>sfm(n);
         
         for(int i =0; i < n; i++)
         {
            if(!i)
            {
                pfm[i] = h[i];
            }
            else
            {
                pfm[i] = max(pfm[i-1] , h[i]);
            }
         }
         sfm[n-1] = h[n-1];

         for(int i = n-2 ; i>=0 ;i--)
         {
            sfm[i] = max(sfm[i+1] , h[i]);
         }

          int ans =0 ; 
         for(int i =0 ; i < n; i++)
         {
            int lm = pfm[i] , sm = sfm[i];
            if(lm > h[i] && sm > h[i])
            {
                ans += (min(lm , sm) - h[i]);
            }
         }

         return ans;
    }
};

int main()
{
    
}