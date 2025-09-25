bool isValidBST(TreeNode* root) {
    vector<int> arr;
    helper(root, arr);

    for(int i=0;i<arr.size()-1;i++){
        if(arr[i] >= arr[i+1]){
            return 0;
        }
    }

    return 1;
}

void helper(TreeNode* root, vector<int> &arr){
    if(root == NULL){
        return;
    }


    helper(root->left, arr);
    arr.push_back(root->val);
    helper(root->right, arr);

}