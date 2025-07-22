
// we have to print verticle traversal of the tree  
// for this we find each nodes loaction as coordinates of verticle and level 
// so  at root we take reference and take it as 0 verticle , left to it minus and right to it plus
// so the coordinate of root in this coordinate system will be (0,0) , its left's coordinate will be (-1 , 0)  : {(verticle , level)}

// if we have to overlapping nodes then we store smaller first
// overlapping means on same level and same verticle , for example root has left and right and both left & right have both left and right
//                 0
                a      b
             c     d  e   f 

//   here d and e are overlapping .

// for marking each nodes coordinate we can use any traversal technique 
// here we use levelwise traversal (bfs)


// here we take a queue which will store (node , {verticle , level})
// along with this we will use a  map<int ,map<int , multiset<int>>>  :  (verticle , {level , nodes in that level}) :- each verticle will have multiple level and each level will have multiple nodes
//w e are using multiset bcoz nodes may be repetive

// code: 

 vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int , map<int , multiset<int>> > mp ; // verticle  => levels => nodes
        queue< pair<TreeNode* ,  pair<int ,int>> >q; // {node ,v {erticle , level} }
        q.push({root,   {0 , 0}});
        
        //  doing bfs , on moving left verticle -= 1 , right verticle += 1;
        // level +=1 

        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            TreeNode* node = x.first;
            int verticle = x.second.first;
            int level = x.second.second;
              mp[verticle][level].insert(node->val);  // mp[vertical][level] = multiset of node values

            if(node -> left) q.push({ node -> left, {verticle -1 , level-1}});
            if(node -> right ) q.push({ node -> right, {verticle +1 , level-1}});
            

        }

        vector<vector<int>>ans;
        for(auto it : mp)
        {
            vector<int>col;
            for(auto it1 : it.second)
            {
               col.insert(col.begin() , it1.second.begin() ,it1.second.end() );
            }
            ans.push_back(col);
        }

        return ans;
    }
