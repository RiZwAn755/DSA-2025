

// rain water trapping , here we are given with heights array where h[i] = height of ith building
// we have to tell how many unit water can be stored between buildings


// here we can observe that the amount of water that can be stored over a building is equall to 
<<<<<<< HEAD
// min of height of building which is tallest at its left and bulding which is tallest at its right minus the hieght of the current buildings




// --------------------------------------avoiding the extra sapce------------------------------------------------------------------

// instead of calculating both leftmax and rightMax we can only calculate min(leftmax , rightMax)

=======
// min of height of building which is tallest at its left and bulding which is tallest at its right minus the hieght of the current building

// Time complexity O(3*N) , space Cmplexity = O(2*N)

#include<bits/stdc++.h>
    #define int long long 
using namespace std;
>>>>>>> 9bc2f20d9ce299c49cbd6a97e058e906e70ef59d

class Solution {
public:
    int trap(vector<int>& h) 
    {
        int n = h.size();
<<<<<<< HEAD
        int l = 0 , r = n-1 ;
        int lmax = 0 , rmax = 0 ,  ans = 0 ;

        while(l < r)
        { 
            if(h[l] <= h[r])
=======
        vector<int>pfm(n); // to store left tallest building's height
        vector<int>sfm(n); // to store right tallest building's height
         
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
>>>>>>> 9bc2f20d9ce299c49cbd6a97e058e906e70ef59d
            {
                if(h[l] < lmax)
                {
                    ans += (lmax-h[l]);
                }
                else 
                {
                    lmax = h[l];

                }
                 l = l+1;
            }
            else 
            {
                if(h[r] < rmax)
                {
                    ans += (rmax - h[r]);
                }
                else
                {
                    rmax = h[r];
                   
                }
                 r = r-1;
            }
        } 

         return ans;
    }
<<<<<<< HEAD
};
=======
};



// --------------------------------------avoiding the extra sapce------------------------------------------------------------------

// instead of calculating both leftmax and rightMax we can only calculate min(leftmax , rightMax)


class Solution {
public:
    int trap(vector<int>& h) 
    {
        int n = h.size();
        int l = 0 , r = n-1 ;
        int lmax = 0 , rmax = 0 ,  ans = 0 ;

        while(l < r)
        { 
            if(h[l] <= h[r])
            {
                if(h[l] < lmax)
                {
                    ans += (lmax-h[l]);
                }
                else 
                {
                    lmax = h[l];

                }
                 l = l+1;
            }
            else 
            {
                if(h[r] < rmax)
                {
                    ans += (rmax - h[r]);
                }
                else
                {
                    rmax = h[r];
                   
                }
                 r = r-1;
            }
        } 

         return ans;
    }
};

signed main()
{
    
}
>>>>>>> 9bc2f20d9ce299c49cbd6a97e058e906e70ef59d
