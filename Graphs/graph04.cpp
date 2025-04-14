// #include<bits/stdc++.h>
// using namespace std ;

// vector<vector<int>>g;
// vector<int>vis;
// int n , m ; 
// bool res = true;

// int  dfs(int i  , int color)
// {
//     vis[i] = color;
    
//     for(auto it : g[i])
//     {
//         if(!vis[it])
//         {
//             dfs(it , 3-color);
//         }
//         else if(vis[i] == vis[it])
//         {
//             color++;
            
//         }
//     }
    
//     return color;
// }



// int main()
// {
//     cin >> n >> m ;
//     g.resize(n+1);
//     vis.assign(n+1 , 0);
    
//     for(int i = 1 ; i <= m ; i++)
//     {
//          int x , y ;
//          cin >> x >> y;
         
//          g[x].push_back(y);
//          g[y].push_back(x);
//     }
    
//     // check if graph is bipartite
//     // chromatic Number = minimum number of colors required to color the nodes of graph so that,
//     // no two neighbpurs of graph have same color
    
//     int chromaticNumber =0 ;
//     for(int i = 1 ; i<= n ; i++)
//     {
//         if(!vis[i])
//         {
//             chromaticNumber = max( chromaticNumber , dfs( i , 1 ));
//         }
//     }
    
//     cout << chromaticNumber;
    
    
// }