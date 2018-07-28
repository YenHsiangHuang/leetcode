#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// The first element of preorder is root.
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder,
                    int preBegin, int preEnd, int inBegin) {
    if (preBegin > preEnd) return nullptr;
    TreeNode* root = new TreeNode(preorder[preBegin]);

    if (preBegin != preEnd) {
        int pos = 0;
        while (inorder[inBegin + pos] != root->val) ++pos;
        root->left = buildTree(preorder, inorder, preBegin + 1, preBegin + pos,
                               inBegin);
        root->right = buildTree(preorder, inorder, preBegin + pos + 1, preEnd,
                                inBegin + pos + 1);
    }

    return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if (preorder.empty()) return nullptr;
    return buildTree(preorder, inorder, 0, preorder.size() - 1, 0);
}

TreeNode* buildTree(std::vector<int>&& preorder, std::vector<int>&& inorder) {
    return buildTree(preorder, inorder);
}

int main(int argc, const char* argv[]) {
    //auto root = buildTree(std::vector<int> {2,1,3,4,5}, std::vector<int> {1,2,3,4,5});
    auto root = buildTree(std::vector<int> {3,9,20,15,7}, std::vector<int> {9,3,15,20,7});
    return 0;
}
