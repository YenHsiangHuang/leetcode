struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;

    if (root->val == sum && !root->left && !root->right) return true;
    sum -= root->val;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

int main(int argc, const char *argv[]) {
    // placeholder
    return 0;
}
