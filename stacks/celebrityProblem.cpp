// in this problem we are given with an  n*n  matrix containing 0 or 1 ,
// if matrix[i][j] == 1 => i knows j , but its not necessory that j knows i
// A person is celebrity if every one knows him and he knows no-one
// find the celebrity


// # persons who know celebrity = n-1
// # person celebrity know =  0

// we will create two array to store people who knows celebrity and other to store the person celebrity know

#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> grid)
{
    int n = grid.size() ; // its n*n grid
    vector<int>kc(n,0) ;// kc => persons who knows celebrity
    vector<int>ck(n , 0) ;// ck => persons whom celebrity knows


    for(int i =0;  i < n; i++)
    {
        for(int j =0 ; j < n; j++)
        {
            if(grid[i][j] == 1)
            {
                kc[j]++; // j is known by some one increase its count
                ck[i]++; // i knows someone
            }
        }
    }

    for(int i =0 ; i < n; i++)
    {
        if(ck[i] == 0 && kc[i] == n-1)
        {
            return i;
        }
    }
}

int main()
{
    int n ; 
    cin >> n; 

    vector<vector<int>>grid(n , vector<int>(n));

    for(int i =0; i < n; i++)
    {
        for(int j =0 ; j <n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = celebrity(grid);

    cout << ans << endl;
}