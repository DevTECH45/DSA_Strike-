/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;      // both null -> symmetric
        if (!t1 || !t2) return false;      // one null, other not -> not symmetric
        if (t1->val != t2->val) return false;

        // outer pair (t1.left, t2.right) and inner pair (t1.right, t2.left)
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};