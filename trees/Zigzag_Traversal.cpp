
// traverse tree node level wise in zig zag manner 


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
         if (!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag = 0 ;

        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;
           
            for(int i =0 ; i < size ; i++)
            {
                 TreeNode* x = q.front();
                 q.pop();
                 level.push_back(x -> val);
                 if(x -> left) q.push(x -> left);
                  if(x -> right) q.push(x -> right);
                  
            }
              if(flag)
            {
                reverse(level.begin() , level.end());
            }
            ans.push_back(level);
            flag = 1-flag;

        }

        return ans; 
    }