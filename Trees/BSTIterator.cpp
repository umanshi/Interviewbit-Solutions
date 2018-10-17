/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode*> s;

BSTIterator::BSTIterator(TreeNode *root) {
    while(!s.empty())
        s.pop();
    
    while(root)
    {
        s.push(root);
        root = root->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(s.empty())
        return false;
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* t = s.top();
    int ans = t->val;
    t = t->right;
    s.pop();
    while(t)
    {
        s.push(t);
        t = t->left;
    }
    return ans;
}   

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
