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
class info {
public:
    int maxi;
    int mini;
    int sum;

    info(int max, int min, int sum) {
        maxi = max;
        mini = min;
        this->sum = sum;
    }
};

class Solution {
public:
    int maxS = 0;
    info helper(TreeNode* root){
        if(root == nullptr) return info(INT_MIN, INT_MAX, 0);

        info left = helper(root->left);
        info right = helper(root->right);

        if(left.maxi < root->val && root->val < right.mini){
            int currS = left.sum + right.sum + root->val;
            maxS = max(maxS, currS);

            return info(
                max(root->val, right.maxi),
                min(root->val, left.mini),
                currS
            );
        }
        return info(INT_MAX, INT_MIN, 0);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxS;
    }
};