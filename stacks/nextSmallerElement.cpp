#include<bits/stdc++.h>
#defint int long long
#define pb push_back
#define endl '\n'
using namespace std ;

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int>nse(n ,-1);
        stack<int>st;

        for(int i = n-1 ; i >= 0; i--)
        {
            while(!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }
            
            if(!st.empty())
            {
                nse[i] = st.top();
            }
            st.push(arr[i]);
        }
        
        return nse;
    } 
};
signed  main()
{
    
}
