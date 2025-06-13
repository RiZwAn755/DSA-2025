 

//  q: find lowest common ancestor of two given nides of a given tree.
//approac dfs the complete tree from node storing parent of each node
// to store parent we use map<node* node*> so that we can get parent of any node in o(1);
// then ham 'p' node k sare ancestors ko unorderd set me store kara lenge (unordered set me element find karna O(1) hota h)
// then ham 'q' k ancestors ko pish karenge usi set me aur koi agr mila jise 'p' ne add kiya h to wo hi ans hai 
  
 void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& par) 
    {
        if (!root) return;
        if (root->left) 
        {
            par[root->left] = root;
            dfs(root->left, par);
        }

        if (root->right) 
        {
            par[root->right] = root;
            dfs(root->right, par);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        unordered_map<TreeNode*, TreeNode*> par;
        dfs(root, par);

        unordered_set<TreeNode*> ancestors;

        while (p) {
            ancestors.insert(p);
            p = par[p];
        }

        while (q) 
        {
            // agr p ne already aisa ancestor add kar dia h jo q ka bhi ancestor h 
            if (ancestors.count(q)) return q;
            q = par[q];
        }

        return nullptr; 
    }