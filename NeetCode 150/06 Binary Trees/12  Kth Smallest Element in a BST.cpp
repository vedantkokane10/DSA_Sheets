int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;
    vector<int> arr;
    inorder(root,arr);

    int ans = arr[k-1];
    return ans;

}

void inorder(TreeNode* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}