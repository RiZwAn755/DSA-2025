question :
          you are given an array of coins and a target sum.
          you need to find the number of ways to make the target sum using the coins.
          you can use any coin any number of times.


#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>&coins,int x , itn currSum , int i )
{
    if(currSum == x)
    {
        return 1;
    }
    if(currSum > x ) return 0 ;

    int take = helper(coins , x , currSum + coins[i] , i);
    int notTake = helper(coins , x , currSum , i+1);

    return take + notTake;
}

int main()
{
  vector<int>coins={1,2,5};
  return helper(coins , 5 , 0 , 0);
    
}