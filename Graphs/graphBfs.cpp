// #include<bits/stdc++.h>
// using namespace std;

// int n , m ; 
// vector<vector<int>>g;
// vector<int>visited;
// vector<int>dist;


// void bfs(int i)
// {
//     visited[i] = 1 ;
//     dist[i] = 0; 
//     queue<int>q ;
//     q.push(i);
   
      
//             while(!q.empty())
//             {
//                 int d = q.front();
//                 q.pop();
//                 for(auto it : g[d])
//                 {
//                     if(!visited[it])
//                     {
//                         visited[it] = 1 ;
//                         dist[it] = dist[d]+1;
//                         q.push(it);
//                     }
//                 }
                
//             }

    
// }




// int main()
// {
//     cin >> n >> m ;
//     g.resize(n+1);
//     visited.assign(n+1 , 0);
//     dist.assign(n+1 , 1e4);
    
//     for(int i = 1 ; i <= m ; i++)
//     {
//         int x , y ;
//         cin >> x >> y ;
        
//         g[x].push_back(y);
//         g[y].push_back(x);
        
//     }
    
//     bfs(1);
//     for(int i = 1 ; i <= n; i++)
//     {
//         cout << i << " " << dist[i] << endl;
//     }
// }
