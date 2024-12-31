 
//  previous smaller element
 // ex: n = 5 :  nums[] = {9, 6, 10, 9, 5}.
    // output : {-1,-1 , 6 ,6 ,6}.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin >> n ;
    
    vector<int>nums(n);
    
    for(int i =0; i< n; i++)
    {
        cin >> nums[i];
    }
    
   
    
    vector<int>pse(n ,-1);
    stack<int>st ;
    
    int mini = 1e8;
    
    for(int i =0 ; i < n ; i++)
    {
           while(!st.empty() && st.top() >= nums[i])
           {
               st.pop();
           }
           
           if(!st.empty())
           {
               pse[i] = st.top();
           }
           st.push(nums[i]);
       
    }
    
    for(auto it : pse)
    {
        cout << it << " ";
    }
    cout << endl;
}