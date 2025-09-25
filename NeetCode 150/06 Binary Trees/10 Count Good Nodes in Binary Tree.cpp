int goodNodes(TreeNode* root) {
    int cnt = 1;
    helper(root->left,root->val,cnt);
    helper(root->right,root->val,cnt);
    return cnt;
}
void helper(TreeNode* root, int maxValue, int &cnt){
    if(root == NULL){
        return;
    }
    int currentValue = root->val;
    if(currentValue >= maxValue){
        cnt++;
        maxValue = currentValue;
    }
    helper(root->left, maxValue, cnt);
    helper(root->right, maxValue, cnt);
}