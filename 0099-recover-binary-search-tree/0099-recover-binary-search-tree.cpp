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
    // there is the possibilities of 2 cases:- 
        // 1) both elements are adjacent pair. 
        // 2) both are not adjacent

        // so i have to mark the 1st wrong element as first and next to it as middle and then find the 2nd wrong element as second if i will found then swap(first, second)  or if i don't get it, it means that first and middle are the 2 elements those are not at their correct positions then swap(first, middle)
class Solution {
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* second;
    TreeNode* prev;

    void inorder(TreeNode* root){
        if(root == nullptr) return;

        inorder(root->left);
        // checking the violation condition
        if(prev != nullptr && (prev->val > root->val)){
            // checking the first is null means that we have not found the first then update the first and middle
            if(first == nullptr){
                first = prev;
                middle = root;
            }
            // else means that we have our first and middle but we dont have our second so update it
            else{
                second = root;
            }
        }
        // prev is used for finding the first and second and also used for the inorder traversal one by one to each node
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        // your code goes here
        first = second = middle = nullptr;
        // we can not initialized it with the value -1 because it can fail for the negative values like (prev = -1)> (root = -20) 
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first != nullptr && second != nullptr){
            swap(first->val, second->val);
        }
        else if(first != nullptr && middle != nullptr){
            swap(first->val, middle->val);
        }  
    }
};