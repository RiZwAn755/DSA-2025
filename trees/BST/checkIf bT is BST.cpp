 void dfs(TreeNode* root,  vector<int>& v)
    {
        if(!root) return ;
      
        if(root -> left ) dfs(root -> left, v );
          v.push_back(root -> val);
        if(root -> right) dfs(root -> right , v);

    }
    bool isValidBST(TreeNode* root) 
    {
        vector<int>INtraversal;
        dfs(root ,INtraversal);

        for(int i =0; i < INtraversal.size()-1 ; i++)
        {
            if(INtraversal[i] >= INtraversal[i+1])
            {
                return false;
            }
        }

        return true;
    }