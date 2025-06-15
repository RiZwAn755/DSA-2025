// can you create a uniquew binary tree , from the given traversals 
        // preorder - 1,
        // inorder - 2, 
        // postorder - 3. 

        // 1 & 3 => cant create a unique tree 
        // inorder and pre=order => true
        
        // ********** if we have inorder then only we can create unique binary tree *******************
        // but theres also need of any one other traversal to make unique tree 

        // code :        return (a == 2 && b!= 2 || b==2 && a!= 2 );
