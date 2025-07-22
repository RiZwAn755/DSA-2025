
// Its traversal technique for inorder and preorder , in O(1) space and O(N) time 

//  Algorithm Steps:
// Let curr = root:

// While curr != NULL:

// If curr->left == NULL:

// Visit curr → ans.push_back(curr->val)

// Move curr = curr->right

// Else:

// Find the rightmost node in the left subtree (predecessor) of curr

// i.e., pre = curr->left, and then while(pre->right != NULL && pre->right != curr) pre = pre->right;

// If pre->right == NULL:

// Make thread: pre->right = curr

// Move curr = curr->left

// Else: (thread already exists)

// Remove thread: pre->right = NULL

// Visit curr :  ans.push_back(curr->val)

// Move curr = curr->right



vector<int> morrisTraversal(Node* root)
{
    Node* curr = root;
    vector<int> ans;

    while (curr)
    {
        if (curr->left == nullptr)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            Node* leftNode = curr->left;

            // Go to the rightmost node of the left subtree
            while (leftNode->right && leftNode->right != curr)
            {
                leftNode = leftNode->right;
            }

            if (leftNode->right == nullptr)
            {
                // Create thread
                leftNode->right = curr;
                curr = curr->left;
            }
            else
            {
                // Thread already exists, remove it and visit curr
                leftNode->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
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
                // we are at a thread
                   leftChild -> right = nullptr;
                   curr = curr -> right ;
               }             
           
               
           }
       }
       
       return ans;
       
    }


