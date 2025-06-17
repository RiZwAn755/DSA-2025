

// in BST inorder traversal is always sorted  
// approach store inorder in a vector and return vector[k-1] 

// another approach  
// do a dfs or bfs store each node and sort then return 

int kthSmallest(TreeNode* root, int k) 
    {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>f;

        while(!q.empty())
        {
            TreeNode* x = q.front();
            q.pop();
            f.push_back(x -> val);

            if(x -> left) q.push(x -> left);
            if(x -> right)  q.push(x -> right);
        }

        sort(f.begin() , f.end());
        return f[k-1];
    }