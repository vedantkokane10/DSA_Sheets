int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int height(TreeNode* root, int &diameter){
    if(root == NULL){
        return 0;
    }

    int leftSubTreeHeight = height(root->left, diameter);
    int rightSubTreeHeight = height(root->right, diameter);

    diameter = max(leftSubTreeHeight + rightSubTreeHeight, diameter);


    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;   
}