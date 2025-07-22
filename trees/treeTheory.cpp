

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
  
// ---------------- iteartive pre-order (Stack) ---------------------------------

// Approach : take the root put it in stack , then push stacks's right then left in the stack , 
// bcoz stack is LIFO so left will come out first.and its children will be pushed in stack after its printing.

//  vector<int> preorder(Node* root) {
        
//         vector<int>ans;
//         stack<Node*>st;
//         st.push(root);
        
//         while(!st.empty())
//         {
//             Node* x = st.top();
//             ans.push_back(x -> data);
//             st.pop();
//             if(x -> right != nullptr) st.push(x -> right); // pushing right element first
//             if(x -> left != nullptr) st.push(x -> left); // then left , bcoz of stacks LIFO order
//         }
        
//         return ans;
        
//     }


// ----------- iterative inorder --------------------

// Approach: make a stack push the root in stack 
// then while stack is not empty we will 
// first push the root and all possile lefts in the stack, now take the top element and push its data in ans,
// then move to right data 

// vector<int> inOrder(Node* root) 
//     {
        
//       vector<int>ans;
//       stack<Node*>st;
//       Node* node = root;
      
//       while(true)
//       {
//          till we reach null ,while taking lefts of all node
//           if(node != nullptr)
//           {
//               st.push(node); 
//               node = node -> left;
//           }
//           else 
//           {
//               if(st.empty())
//               {
//                   break;
//               }
              
//               node = st.top();
//               st.pop();
              
//               ans.push_back(node -> data);
//               node = node -> right;
//           }
//       }
      
    
      
//       return ans;
//     }

// --------------------------- Iterative post order (Two stacks) -------------------

// vector<int> PostOrder(Node* root)
// {
//     vector<int>ans;
//     stack<Node*>st1 , st2 ;

//     st1.push(root);

//     while(!st1.empty())
//     {
//         Node* x = st1.top();
//         st1.pop();
//         st2.push(x);


//         if(x -> left) st1.push(x -> left);
//         if(x -> right) st1.push(x -> right);
//     }
    
//     while(!st2.empty())
//     {
//         ans.push_back(st2.top() -> data);
//         st2.pop();
//     }

//     return ans;

// }

// ----------------------- Post Order using single stack -----------------------------

// in recurrsion we were doing 
//   1. left 
//   2. right
//   3. print

// means keep on going left till we find null ,
// then go right , if we find a null then again keep going left 
// then after that we print

    // vector<int>PostOrder(Node* root)
    // {
    //     Node* curr = root; 
    //     stack<Node*>st;
    //     while(curr != nullptr || ! st.empty()) // while curr is not null or stack is not empty
    //     {
    //          if(curr != nullptr)
    //          {
    //             st.push(curr);
    //             curr = curr -> left ;
    //          }

    //          else 
    //          {
    //             Node* temp = st.top() -> right;
    //             if(temp == nullptr)
    //             {
    //                 temp = st.top();
    //                 st.pop();
    //                 ans.push_back(temp -> data);

    //                 while(!st.empty() && temp == st.top() -> right)
    //                 {
    //                     temp = st.top();
    //                     st.pop();
    //                     ans.push_back(temp -> data);
    //                 }
    //             }
    //             else 
    //                 curr = temp; // to loop again in left
    //          }
    //     }
    //     return ans;
    // }


    // ------------------------ all three traversal in one code using one stack ------------------------

    //  if number is 1 => push it in preOrder and num++ ,if theres a  Left also put it in stack
    //  else if num is 2 => push it in inorder and num++ , if theres a  Right also put it in stack
    //  else if num is 3 => push it in postOrder 

    //  vector<vector<int> AllTraversal(Node* root)
    //  {
    //     stack<pair<Node* , int>> st;
    //     vector<int> pre , in , post ;
    //     vector<vector<int>>ans;

    //     st.push({root , 1});
    //     while(!st.empty()){

    //         auto &it = st.top();
    //         if(it.second == 1)
    //         {
    //            pre.push_back(it.first -> data);
    //            it.second++;
    //            if(it.first -> left)
    //            {
    //             st.push(it.first -> left , 1);
    //            }
    //         }
    //         else if(it.second == 2)
    //         {
    //              in.push_back(it->first->data);
    //              it.second++;
    //              if(it.first -> right)
    //              {
    //                 st.push(it.first -> right , 1);
    //              }
    //         }
    //         else 
    //         {
    //             post.push_back(it.first -> data) ;
    //         }
    //     }
    //     ans.push_back(pre);
    //     ans.push_back(in);
    //     ans.push_back(post);

    //     return ans;
    //  }
