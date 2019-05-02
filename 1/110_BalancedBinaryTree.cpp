#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// If subtrees are balanced, return height of node
// If subtrees are unbalanced, return -1
int getHeight(TreeNode *root) {
    if (root == nullptr) return 0;

    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);

    if (lHeight < 0 || rHeight < 0 || std::abs(lHeight - rHeight) > 1) return -1;

    return std::max(lHeight, rHeight) + 1;
}

bool isBalanced(TreeNode *root) {
    return (getHeight(root) == -1) ? false : true;
}

int main(int argc, const char *argv[]) {
    // placeholder
    return 0;
}
