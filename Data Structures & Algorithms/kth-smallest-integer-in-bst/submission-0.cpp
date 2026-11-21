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
        // arr = [2, 1, 4], k = 1 

       /*    2
            / \
           /   \
           1   4  
     */

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& v){
        if(!root){
            return;
        }
        preorder(root->left, v);
        v.push_back(root->val);
        preorder(root->right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        preorder(root, v);
        return v[k-1];
    }
};
