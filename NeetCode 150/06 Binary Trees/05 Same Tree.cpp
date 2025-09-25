bool isSameTree(TreeNode* p, TreeNode* q) {
    return preorder(p,q);
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