#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// The last element of postorder is root.
TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder,
                    int inBegin, int postBegin, int postEnd) {
    if (postBegin > postEnd) return nullptr;
    TreeNode* root = new TreeNode(postorder[postEnd]);

    if (postBegin != postEnd) {
        int pos = 0;
        while (inorder[inBegin + pos] != root->val) ++pos;
        root->left = buildTree(inorder, postorder, inBegin,
                               postBegin, postBegin + pos - 1);
        root->right = buildTree(inorder, postorder, inBegin + pos + 1,
                                postBegin + pos, postEnd - 1);
    }

    return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    if (inorder.empty()) return nullptr;
    return buildTree(inorder, postorder, 0, 0,
                     postorder.size() - 1);
}

TreeNode* buildTree(std::vector<int>&& inorder, std::vector<int>&& postorder) {
    return buildTree(inorder, postorder);
}

int main(int argc, const char* argv[]) {
    auto root = buildTree(std::vector<int>{9, 3, 15, 20, 7},
                          std::vector<int>{9, 15, 7, 20, 3});
    return 0;
}
