bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    vector<TreeNode*> arr;
    helper(root,subRoot->val,arr);
    for(auto x:arr){
        if(preorder(x,subRoot) == 1){
            return 1;
        }
    }
    return 0;
}

void helper(TreeNode* root, int startValue, vector<TreeNode*> &arr){
    if(root == NULL){
        return;
    }
    if(root->val == startValue){
        arr.push_back(root);
    }
    helper(root->left,startValue,arr);
    helper(root->right,startValue,arr);
}

bool preorder(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL){
        return 1;
    }
    else if(p == NULL && q != NULL){
        return 0;
    }
    else if(p != NULL && q == NULL){
        return 0;
    }
    else if(p->val != q->val){
        return 0;
    }

    if(preorder(p->left,q->left) == 0){
        return 0;
    }
    if(preorder(p->right,q->right) == 0){
        return 0;
    }
    return 1;
}