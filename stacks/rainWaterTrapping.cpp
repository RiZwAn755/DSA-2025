

// rain water trapping , here we are given with heights array where h[i] = height of ith building
// we have to tell how many unit water can be stored between buildings


// here we can observe that the amount of water that can be stored over a building is equall to 
// min of height of building which is tallest at its left and bulding which is tallest at its right minus the hieght of the current buildings




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