/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int sumNumbers(TreeNode *root) { return util(root, 0); }

    int util(TreeNode *root, int result)
    {
        if (root == nullptr)
            return 0;

        result = result * 10 + root->val;

        if (root->left == NULL && root->right == NULL)
            return result;

        return util(root->left, result) + util(root->right, result);
    }
};