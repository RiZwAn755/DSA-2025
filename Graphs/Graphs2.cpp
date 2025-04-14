
// find number of components


// #include<bits/stdc++.h>
// using namespace std ;

// vector<vector<int>>g;
// vector<int>visited;
// int n , m ; 

// void dfs(int i )
// {
//     visited[i] =1 ;
    
//     for(auto it : g[i])
//     {
//         if(!visited[it])
//         {
           
//             dfs(it );
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m ;
//     g.resize(n+1);
//     visited.assign(n+1 , 0);
    
//     // taking edges as input
    
//     for(int i = 1  ; i <= m ; i++)
//     {
//         int x , y ; 
//         cin >> x >> y ;
        
//         g[x].push_back(y);
//         g[y].push_back(x);
        
//     }
    
//     int components = 0;
    
    
//     for(int i = 1 ; i <= n; i++)
//     {
//         if(!visited[i])
//         {
//             dfs(i);
//             components++;
//         }
//     }
    
//     cout << components << endl;
// }
