bool isBalancedValue = 1;
bool isBalanced(TreeNode* root) {
    height(root);
    return isBalancedValue;
}
int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int leftSubtreeHeight = height(root->left);
    int righttSubtreeHeight = height(root->right);

    int diff = max(leftSubtreeHeight,righttSubtreeHeight) - min(leftSubtreeHeight,righttSubtreeHeight);

    if(diff > 1){
        isBalancedValue = 0;
        return 0;
    }

    return max(leftSubtreeHeight, righttSubtreeHeight) + 1;
    }