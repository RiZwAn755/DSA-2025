  map<int , int> mp;
     int postIndex ;
     TreeNode* solve(vector<int>& in, vector<int>& post , int inStart , int inEnd)
     {
        if(inStart > inEnd) return nullptr ;
        int curr_root = post[postIndex--];

        TreeNode* node = new TreeNode(curr_root);
        
        // if its leaf
        if(inStart == inEnd) return node;

        int inIndex = mp[curr_root];

       // first right then left
        node->right = solve(in, post, inIndex + 1, inEnd);
        node->left = solve(in, post, inStart, inIndex - 1);

        return node;
     }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) 
    {
        postIndex = post.size()-1;
        for(int i =0;  i< in.size() ; i++)
        {
            int v = (in[i]);
            mp[v] = i ;
        }

       return solve(in , post , 0, in.size()-1 );
    }
