

// // #include<bits/stdc++.h>

// using namespace std;

// vector<vector<int>>g; // edge list
// int n  , m ; 
// vector<int>visited;

// void dfs(int i)
// {
//     visited[i] = 1;
//     for(auto it : g[i])
//     {
//         if(!visited[it])
//         {
//             dfs(it);
//         }
//     }
// }

// int main()
// {
//      cin >> n >> m ;
     
//     g.resize(n+1);
//     visited.assign(n+1 , 0);
    
    
//     for(int i = 1 ; i <= m ; i++)
//     {
//         int x , y ;
//         cin >> x >> y ;
        
//         g[x].push_back(y);
//         g[y].push_back(x); // bi derectional graph
//     }
    
//     dfs(1);
    
//     for(int i =1  ; i < visited.size() ; i++)
//     {
//         cout << i << " " << visited[i] << endl;
//     }
// }
