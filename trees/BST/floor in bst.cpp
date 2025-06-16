  Node* flooor(Node* root, Node*& ans, int x) {
    if (!root) return ans;

    if (root->data <= x) {
        // update the floor candidate
        if (!ans || root->data > ans->data)
            ans = root;
        return flooor(root->right, ans, x);
    } else {
        return flooor(root->left, ans, x);
    }
}

int floor(Node* root, int x) {
    Node* ans = nullptr;
    flooor(root, ans, x);
    return ans ? ans->data : -1;
}
};