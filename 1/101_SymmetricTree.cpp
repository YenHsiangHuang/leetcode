struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left != nullptr || right != nullptr) return false;
    if (left->val != right->val) return false;

    return isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
}


int main(int argc, const char *argv[]) {

    return 0;
}
