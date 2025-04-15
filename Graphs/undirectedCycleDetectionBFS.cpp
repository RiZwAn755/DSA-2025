// // Dectect Cycle in undirected Graph using bfs


// #include<bits/stdc++.h>
// using namespace std ;

// vector<vector<int>>g;
// vector<int>vis;
// int n , m ; 


// bool bfs(int src)
// {
//     vis[src] = 1;
    
//     // {child , parent}
//     queue<pair <int , int >> q ;
//     q.push({src , -1});
    
//     while(!q.empty())
//     {
//         auto x = q.front();
//         // x.first = child 
//         // x.second = parent
//         q.pop();
//         for(auto it : g[x.first])
//         {
//             if(!vis[it])
//             {
//                 vis[it] = 1;
//                 q.push({it , x.first});
//             }
//             else if(x.second != it) // it is visited by some else node
//             {
//                return true;
//             }
//         }
//     }
//     return false;
// }


// int main()
// {
//     cin >> n >> m ; 
//     g.resize(n+1);
//     vis.assign(n+1 , 0);
    
//     for(int i =1 ; i <= m; i++)
//     {
//         int x , y ;
//         cin >> x >> y ;
        
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
    
//     for(int i =1 ; i <= n ; i++)
//     {
//         if(!vis[i])
//         {
//             if(bfs(i))
//             {
//                 cout << "YES"<<endl;
//                 return 0;
//             }
//         }
//     }
    
//    cout <<  "NO" <<endl;
//    return 0;
// }


// input 
// 4 3
// 1 2
// 2 3
// 3 4

// output : NO 