  int minTime(Node* root, int target)
{
    if (!root) return 0;

    map<Node*, Node*> parent;  
    Node* targetNode = nullptr;

    // Step 1: BFS to build parent map and find target node
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        if (curr->data == target) targetNode = curr;

        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }

    // BFS from target to simulate burning
    map<Node*, bool> visited;
    queue<Node*> q1;
    q1.push(targetNode);
    visited[targetNode] = true;
    int time = 0;

    while (!q1.empty()) {
        int size = q1.size();
        bool burned = false;

        for (int i = 0; i < size; i++) {
            Node* node = q1.front(); q1.pop();

            
            if (node->left && !visited[node->left]) {
                visited[node->left] = true;
                q1.push(node->left);
                burned = true;
            }

           
            if (node->right && !visited[node->right]) {
                visited[node->right] = true;
                q1.push(node->right);
                burned = true;
            }

         
            if (parent.find(node) != parent.end() && !visited[parent[node]]) {
                visited[parent[node]] = true;
                q1.push(parent[node]);
                burned = true;
            }
        }

        if (burned) time++;
    }

    return time;
}