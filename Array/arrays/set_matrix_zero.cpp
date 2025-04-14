// #include<bits/stdc++.h>
// using namespace std;



// problem : given a 2D matrix , if any element is zero , set all its row and column to zero
// approach : first store the occurances if zeros , then go to each zero and make its row and column as zero.

// class Solution {
//     public:
//         void setZeroes(vector<vector<int>>& matrix) 
//         {
//             int n = matrix.size();
//             int m = matrix[0].size();
    
//             vector<pair<int,int>>v; // stores the zeros positions
    
//             for(int i =0 ; i < n; i++)
//             {
//                 for(int j =0 ; j < m; j++)
//                 {
//                     // if i find any zero 
//                     if(matrix[i][j] == 0)
//                     {
//                         v.push_back({i,j});
//                     }
//                 }
//             }
    
//             for(int i =0 ; i < v.size() ;i++)
//             {
//                 int p = v[i].first;
//                 int q = v[i].second;
//                 // making cols = 0
//                         for(int k =0 ; k < m; k++)
//                         {
//                             matrix[p][k] = 0;
//                         }
    
//                         // making  rows = 0                    
//                         for(int l =0 ; l < n; l++)
//                         {
//                             matrix[l][q] = 0;
//                         }
//             }
//         }
//     };

//     int main()
//     {

//     }