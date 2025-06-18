
// tree traversal in O(1) space and O(N) time. 

// uses the concept of threaded binary tree.

//approach :  go to root's left , and if its right child exists then got last right child and connect that to root.

// INORDER TRAVERSAL 
// left 
// root 
// right


vector<int> inOrder(Node* root) 
    {
        if(!root) return {};
       vector<int>ans;
       Node* curr = root ;
       
       while(curr)
       {
           if(curr -> left == nullptr)
           {
               ans.push_back(curr -> data);
               curr = curr -> right ;
           }
           else
           {
               Node* leftChild = curr -> left;
               
               while(leftChild -> right && leftChild -> right != curr)
               {
                   leftChild = leftChild -> right;
               }
               
               if(leftChild -> right == nullptr)
               {
                   leftChild -> right = curr;
                   curr = curr -> left ;
               }
               
               else
               {
                   leftChild -> right = nullptr;
                   ans.push_back(curr -> data);
                   curr = curr -> right ;
               }
               
           
               
           }
       }
       
       return ans;
       
    }


    // preorder 

    vector<int> inOrder(Node* root) 
    {
        if(!root) return {};
       vector<int>ans;
       Node* curr = root ;
       
       while(curr)
       {
           if(curr -> left == nullptr)
           {
               ans.push_back(curr -> data);
               curr = curr -> right ;
           }
           else
           {
               Node* leftChild = curr -> left;
               
               while(leftChild -> right && leftChild -> right != curr)
               {
                   leftChild = leftChild -> right;
               }
               
               if(leftChild -> right == nullptr)
               {
                   leftChild -> right = curr;
                    ans.push_back(curr -> data); // in case of preorder 
                   curr = curr -> left ;
               }
               
               else
               {
                   leftChild -> right = nullptr;
                  
                   curr = curr -> right ;
               }
               
           
               
           }
       }
       
       return ans;
       
    }


