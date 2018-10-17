int height (TreeNode* A)
{
    if (!A) return 0;
    return (1+max(height(A->left), height(A->right)));
}
int Solution::isBalanced(TreeNode* A) {
    if(!A) return 1;
    int l_h = height(A->left);
    int r_h = height(A->right);
    if(isBalanced(A->left) && isBalanced(A->right) && (l_h-r_h>=-1) && (l_h-r_h<=1))
        return 1;
    return 0;
}
