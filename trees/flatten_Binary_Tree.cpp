// flattening tree in linkedList like structure, nodes from preOrder traversal 


void preOrder(TreeNode* root , TreeNode*& ans)
      {
        if(!root) return ;
        
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;

        ans -> right = root ;
        ans -> left = nullptr;
        ans = ans -> right ;

        preOrder(left , ans);
        preOrder(right , ans);

      }
    void flatten(TreeNode* root) 
    {
        TreeNode* ans = new TreeNode(-1);
        TreeNode* res = ans;

        preOrder(root , ans);
        root = res -> right;
    }
