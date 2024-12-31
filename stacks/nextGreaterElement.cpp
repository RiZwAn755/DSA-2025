
// next greater element(NGE) => find the just next element that is greater then the element ,if no element then return -1.

// brute force -> 2 for loops (1).i from 0 to n && (2). j from i+1 to n; ==> o(n^2)

// better optimization  -> traverse from the back so that for each index i know whats in its right

// lets have a stack , if stack is emepty then we nge[i] = -1 i.e no elemnt greater, and then push that element in stack 
// on moving back if we get any number we see that is smaller than st.top(), then we assign the nge of that element to be st.top(),
//  if we get any element that is greater than st.top() then we pop stack untill stack gets empty or we found an element in stack that is greater than the element


 
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main()
{
   int arr[4] = {1, 2, 3, 4};
   int nge[4] = {-1, -1, -1, -1};

   stack<int> st;
   for (int i = 3; i >= 0; i--) 
   {
       if (st.empty()) 
       {
           nge[i] = -1;
           st.push(arr[i]);
       }
       else if (arr[i] < st.top()) 
       {
           nge[i] = st.top();
           st.push(arr[i]);
       }
       else 
       {
           while (!st.empty() && st.top() <= arr[i]) 
           {
               st.pop();
           }
           if (st.empty()) 
           {
               nge[i] = -1;
           } else 
           {
               nge[i] = st.top();
           }
           st.push(arr[i]);
       }
   }

   for (int i = 0; i < 4; i++) 
   {
       cout << nge[i] << " ";
   }

   
}
