int maxDepth(TreeNode* root) {
    return height(root);
}

int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int leftSubtreeHeight = height(root->left);
    int righttSubtreeHeight = height(root->right);

    return max(leftSubtreeHeight, righttSubtreeHeight) + 1;
}