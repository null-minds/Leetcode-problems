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
        if (root == nullptr) {
            return true; // An empty tree is symmetric
        }
        return symmetry(root->left, root->right);
    }

private:
    bool symmetry(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true; // Both nodes are null, so symmetric
        }

        if (left == nullptr || right == nullptr) {
            return false; // One of the nodes is null, so not symmetric
        }

        if (left->val != right->val) {
            return false; // The values of the nodes do not match, so not symmetric
        }

        // Recursively check the children of the nodes
        return symmetry(left->left, right->right) && symmetry(left->right, right->left);
    }
};