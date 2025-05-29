 
 // find maximum depth of the tree
 // Approach : 1 recurrsive  , 2 iterative bfs

 // recurrsive Approach :

//  TC : O(N)
//  SC :O(h) 

//  max height = 1 + max( maxHeight in left  , maxHeight in right) 

//  int MaxHeight(Node* root)
//  {
//     if(root == nullptr)
//     {
//         return 0;
//     }
//     return 1 + max(MaxHeight(root -> left) , MaxHeight(root -> right) );
//  }
  

// Approach 2 ( iterative ) using bfs

// int MaxHeight(Node* root)
// {
   
//     int ans = 1 ;
//     if(root == nullptr)
//     {
//         return 0;
//     }

//      queue<Node*>q;
//     q.push(root);

//     while(!q.empty())
//     {
//         int levelSize = q.size();  

     
//         for (int i = 0; i < levelSize; i++) 
//         {
//             Node* node = q.front();
//             q.pop();

//             if (node->left)
//                 q.push(node->left);
//             if (node->right)
//                 q.push(node->right);
//         }
//       ans++;
      
//     }

//     return ans;
// }