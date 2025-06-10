// we will be using verticles concept of verticle order traversal 
// first node of each verticle will be our answer
 
 vector<int> topView(Node *root) {
    if (!root) return {}; // handle empty tree case
    
    queue<pair<Node*, int>> q; // node, vertical
    map<int, Node*> mp; // vertical, node
    
    q.push({root, 0});
    
    while (!q.empty()) {
        auto x = q.front();
        Node* node = x.first;
        int vertical = x.second;
        q.pop();
        
        // Only store the first node we encounter at each vertical position
        
            mp[vertical] = node;
        }
        
        if (node->left) q.push({node->left, vertical - 1});
        if (node->right) q.push({node->right, vertical + 1});
    }
    
    vector<int> ans;
    for (auto it : mp) {
        ans.push_back(it.second->data);
    }
    
    return ans;
}


