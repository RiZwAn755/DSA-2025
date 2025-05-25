

// trees are hierarchial data structure ,its not linear data structure
// binary tree :- each node has max of 2 child
// root of tree :- starting node of tree 
// leaf node :- node which do not have any child
// ancestors :- parents , grandParents and so on , all are called acestors

// ------------------------- types of binary trees ------------------------------
// 1. full binary tree :- every node have either of zero or two child 
// 2. complete binary trees :- all the levels are completely filled except last level and last level has all nodes in left , i.e level1 = 1 node , l2 = 2 node , l3 = 4 nodes
// 3. prefect binary tree :- all the leaf nodes are at same level 
// 4. balanced binary tree :- height of the tree is atmax log(n) , n = # of nodes
// 5. degenerate trees :- tree looks like staright line 




//---------------------------Represntation in c++ ---------------------------------
 
//   create a class node 
 //  node =   (left pointer + data + right pointer)

//  code 


// #include <bits10_1.h>
// using namespace std;

//  class Node 
//  {
//     public :

//     int data ;
//     Node* left ;
//     Node* right;

//      // constructor 
//     Node(int val)
//     {
//        data = val ;
//        left = nullptr;
//        right = nullptr;
//     }

//  } ;

//  int main()
//  {
//     // method1  

//     Node* a = new Node(3); // dynamic allocation
//     cout << a->data<< endl;

//     a -> left  = new Node(4);
//     a -> right = new Node(5) ;

//     // method 2 

//     // Node a(3);              // stack allocation
//     // cout << a.data << endl;
//  }


 // ------------------ traversal techniques in trees --------------------------------------
 
//  1. DFS  => INORDER , PREORDER , POSTORDER   : (LEFT THEN RIGHT ALWAYS , PRE MEANS ROOT WILL COME BEFORE L AND R , IN MEANS ROOT WILL COME BETWEN THEM)

//  2. BFS  (LEVEL WISE )



// --------------------------- DFS -----------------------
//  TC O(N) 
// 1. pre order 

// void preOrder(Node* node)
// {
//     if(node == nullptr)
//     {
//         return ;
//     }

//     cout << node -> data ;
//     preOrder(node -> left);
//     preOrder(node -> right) ;

//     // inOrder :
//     inOrder( node -> left) ;
//     cout << node -> data ;
//     inOrder(node -> right);

//     // postOrder 

//     postOrder(node -> left);
//     postOrder(node -> right);
//     cout << node -> data ;
// }


// ------------------ BFS ----------------------------
// TC O(n) 

// vector<vector<int>> levelOrder(Node *root) 
//     {
    
//       vector<vector<int>>ans;
//       queue<Node*>q;
//       q.push(root);
      
//       while(!q.empty())
//       {
         
//           vector<int>level;
//           for(int i =0 ; i < q.size() ; i++)
//           {
//                Node* x = q.front();
//                q.pop();
//                if(x -> left != nullptr) q.push(x -> left);
//                if(x -> right != nullptr) q.push(x -> right);
//                level.push_back(x -> data);
//           }
          
//           ans.push_back(level);
//       }
         
//          return ans ;
        
//     }
  