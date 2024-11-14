/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL) {
            return NULL;
        }
        
        // return the current node if it is 'p' or 'q'
        if (root == p || root == q){
            return root;
        }

        TreeNode* left_sub = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_sub = lowestCommonAncestor(root->right, p, q);

        // This is the LCA condition
        if (left_sub != NULL && right_sub != NULL){
            return root;
        }

        // when only one sub tree returns a result
        return (left_sub != NULL) ? left_sub : right_sub;
    }
};