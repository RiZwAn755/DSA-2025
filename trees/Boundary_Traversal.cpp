
// traversing left nodes 

void addLeft(Node* root , vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if (curr->left || curr->right)
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// traversing leaf node
    
    void addLeaf(Node* root , vector<int>& res)
    {
        if(!root) return ;
        
        if(!root -> left && !root -> right)
        {
            res.push_back(root -> data);
        }
        
        addLeaf(root -> left , res);
        addLeaf(root -> right , res);
    }
  
    // traversing right nodes
   void addRight(Node* root, vector<int>& res) 
   {
       
    Node* curr = root->right;
    vector<int> temp;
    
    while (curr) 
    {
        
        if (curr->left || curr->right)
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    
    reverse(temp.begin(), temp.end());
    res.insert(res.end(), temp.begin(), temp.end());
}

    vector<int> boundaryTraversal(Node *root) 
    {
        if(!root) return {};
        vector<int>ans;
        
        if(root -> left || root -> right)
        {
            ans.push_back(root -> data);
        }
        
        addLeft(root , ans);
        addLeaf(root , ans);
        addRight(root , ans);
        
        return ans;
        
    }