 // Q: print nodes at a distance of  K FROM THE GIVEN TARGERT NODE
 
// STEP1: MAKES PARENTS OF EACH NODE OF TREE 
// STEP2 : BFS FROM TRAGET NODE GO LEFT , RIGHT AND PARENT  AND MAKE SURE VISITED NODES ARENT VISITED AGAIN
// STEP3: If level was found to be k, break the BFS and return the current queue elements.
// This is handled after the BFS loop by collecting all nodes left in the queue (which are at distance k from target).

 
 vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{
    vector<vector<int>> ans;
    queue<TreeNode*> q; 
    map<TreeNode*, TreeNode*> mp;
    

    q.push(root);
    while (!q.empty()) {
        TreeNode* x = q.front();
        q.pop();                
        if (x->left) {
            mp[x->left] = x;
            q.push(x->left);
        }
        if (x->right) {
            mp[x->right] = x;
            q.push(x->right);
        }
    }

    queue<TreeNode*> q1;
    unordered_set<TreeNode*> vis;  
    q1.push(target);
    vis.insert(target);
    int level = 0;

    while (!q1.empty()) {
        int size = q1.size();
        if (level == k) break;

        for (int i = 0; i < size; i++) {
            TreeNode* x = q1.front();
            q1.pop();

            if (x->left && !vis.count(x->left)) {
                q1.push(x->left);
                vis.insert(x->left);
            }
            if (x->right && !vis.count(x->right)) {
                q1.push(x->right);
                vis.insert(x->right);
            }
            if (mp.count(x) && !vis.count(mp[x])) {
                q1.push(mp[x]);
                vis.insert(mp[x]);
            }
        }
        level++;
    }

    // Step 3: Collect nodes at distance k
    vector<int> res;
    while (!q1.empty()) {
        res.push_back(q1.front()->val);
        q1.pop();
    }

    return res;
}