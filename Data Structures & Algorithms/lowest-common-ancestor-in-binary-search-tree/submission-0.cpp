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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return root;
        }
        if ((p->val <= root->val && q->val >= root->val) ||
            (p->val >= root->val && q->val <= root->val))
            return root;
        if (p->val < root->val && q->val < root->val) {
            return dfs(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return dfs(root->right, p, q);
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        case 1 - p <= root and q >= root, then return root; / vice versa ( p is bigger than q)

        case 2 - p < root and q < root, then traverse in left subtree from root node

        case 3 - p > root and q > root, then traverse in right subtree from root node

        
         */
        return dfs(root, p, q);
    }
};
