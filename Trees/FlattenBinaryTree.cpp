
void flat(TreeNode* A)
{   
    if(!A) return;
    if(!A->left && !A->right) return;
    
    flat(A->left);
    flat(A->right);
    
    if(!A->left && A->right) return;
    if(A->left && !A->right){
        A->right = A->left;
        A->left = NULL;
        return;
    }
    TreeNode* ptr = NULL;
    if(A->left)
    {
        ptr = A->left;
        while(ptr->right)
            ptr = ptr->right;
        ptr->right = A->right;
    }
    A->right = A->left;
    A->left = NULL; 
}
TreeNode* Solution::flatten(TreeNode* A) {
    flat(A);
    return A;
}
