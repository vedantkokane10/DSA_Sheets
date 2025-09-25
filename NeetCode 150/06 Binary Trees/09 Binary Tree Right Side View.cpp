vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    queue<TreeNode*> q1;
    q1.push(root);
    while(!q1.empty()){
        int n = q1.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            TreeNode* node = q1.front();
            temp.push_back(node->val);
            q1.pop();
            if(node->left != NULL){
                q1.push(node->left);
            }
            if(node->right != NULL){
                q1.push(node->right);
            }
        }
        ans.push_back(temp[temp.size()-1]);
    }

    return ans;
}