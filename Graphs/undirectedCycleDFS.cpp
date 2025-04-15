// // Dectect Cycle in undirected Graph using dfs


// #include<bits/stdc++.h>
// using namespace std ;

// vector<vector<int>>g;
// vector<pair<int ,int>>vis;
// int n , m ; 


// bool dfs(int src , int pr)
// {
//     vis[src] = {1,pr};
    
//    for(auto it : g[src])
//    {
//        if(vis[it].first != 1)
//        {
//            dfs(it , src); // parent is src
//        }
//        else if(it != pr ) // 'it' is visited and its not parent then its cycle
//        {
//            return true;
//        }
//    }
   
//    return false;
// }


// int main()
// {
//     cin >> n >> m ; 
//     g.resize(n+1);
//     vis.assign(n+1 , {0,0});
    
//     for(int i =1 ; i <= m; i++)
//     {
//         int x , y ;
//         cin >> x >> y ;
        
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
    
//     for(int i =1 ; i <= n ; i++)
//     {
//         if(!vis[i].first)
//         {
//             if(dfs(i , i))
//             {
//                 cout << "YES"<<endl;
//                 return 0;
//             }
//         }
//     }
    
//    cout <<  "NO" <<endl;
//    return 0;
// }