  TreeNode* dfs(TreeNode*& root , int x)
    {
        if(!root) return nullptr;
        if(root -> val == x) return helper(root);
        
        TreeNode* dummy = root ;
        
        while(root)
        {
            if(root -> val > x)
            {
                 if(root->left && root -> left ->val == x)
                 {
                    root -> left = helper(root-> left );
                    break;
                 }
                 else 
                 root = root -> left ;
            }
            else
            {
              if(root -> right && root -> right -> val == x)
              {
                 root -> right = helper(root-> right);
                 break;
              }
              else 
              root = root -> right;
              
            }
        }
         
         return dummy ;
    }
    
    TreeNode* helper(TreeNode* root)
    {
        if(!root -> left)
        {
            return root-> right;
        }
        
        if(!root -> right)
        {
            return root-> left;
        }
        
        TreeNode* rightChild = root -> right;
        
        TreeNode* lastRight = findLastRight(root->left);
        
        lastRight -> right = rightChild;
        
          TreeNode* newRoot = root->left;
           
           return newRoot;
    }
    
    TreeNode* findLastRight(TreeNode* root)
    {
        while(root && root -> right)
        {
            root = root -> right;
        }
        return root ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return dfs(root , key);

    }