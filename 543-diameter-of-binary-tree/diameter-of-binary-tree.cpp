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
//done with reference
 pair<int, int> calc(TreeNode* root) {
        if (root == NULL) return {0, 0};

        auto leftData = calc(root->left);
        auto rightData = calc(root->right);

        int currentDiameter = max(leftData.second + rightData.second, 
                                  max(leftData.first, rightData.first));

        int currentHeight = max(leftData.second, rightData.second) + 1;

        return {currentDiameter, currentHeight};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return calc(root).first;
    }
};