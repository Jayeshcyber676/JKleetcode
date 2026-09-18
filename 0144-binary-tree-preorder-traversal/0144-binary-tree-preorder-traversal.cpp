class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        ans.push_back(root->val);              // Root
        vector<int> left = preorderTraversal(root->left);   // Left
        ans.insert(ans.end(), left.begin(), left.end());

        vector<int> right = preorderTraversal(root->right); // Right
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};