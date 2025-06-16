 void preOrder(TreeNode* root , TreeNode*& ans)
      {
        if(!root) return ;
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;

       ans -> left = nullptr ;
        ans -> right = root;
        ans = ans -> right;

      if(root -> left)  preOrder( left , ans );
       if(root -> right) preOrder(right , ans);

      }
    void flatten(TreeNode* root) 
    {
        if(!root) return ;

        TreeNode* ans = new TreeNode(-1);
        TreeNode* res = ans;

        preOrder(root , res);
        root -> left = nullptr;
        root = ans -> right -> right ; 
        

    }