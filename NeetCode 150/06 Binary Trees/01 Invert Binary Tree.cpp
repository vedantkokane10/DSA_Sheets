TreeNode* invertTree(TreeNode* root) {
    if(root == NULL){
        return root;
    }
    queue<TreeNode*> q1;
    q1.push(root);
    while(!q1.empty()){
        int n = q1.size();
        for(int i=0;i<n;i++){
            TreeNode* node = q1.front();
            q1.pop();
            TreeNode* leftNode = node->left;
            TreeNode* rightNode = node->right;
            node->left = rightNode;
            node->right = leftNode;
            if(node->left != NULL){
                q1.push(node->left);
            }
            if(node->right != NULL){
                q1.push(node->right);
            }
        }
        
    }

    return root;
}