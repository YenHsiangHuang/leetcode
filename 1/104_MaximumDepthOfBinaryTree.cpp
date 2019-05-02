#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// This one is really cool!
int maxDepth(TreeNode *root) {
    if (!root) return 0;
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

/*
inline bool isLeaf(TreeNode* node) {
    return node->left == nullptr && node->right == nullptr;
}

void maxDepth(TreeNode *node, int& currDepth, int& depth) {
    if (!node) return;

    if (currDepth > depth && isLeaf(node)) depth = currDepth;

    ++currDepth;
    maxDepth(node->left, currDepth, depth);
    maxDepth(node->right, currDepth, depth);
}

int maxDepth(TreeNode *root) {
    int depth = 0, currDepth = 0;
    maxDepth(root, currDepth, depth);
    return depth;
}
*/

int main(int argc, const char *argv[]) {
    // placeholder
    return 0;
}
