struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

void connect(TreeLinkNode *root, TreeLinkNode *rightNeighbor) {
    if (!root) return;
    root->next = rightNeighbor;

    connect(root->left, root->right);
    if (rightNeighbor) connect(root->right, root->next->left);
    else               connect(root->right, nullptr);
}

void connect(TreeLinkNode *root) { connect(root, nullptr); }

int main(int argc, const char *argv[]) {
    // placeholder
    return 0;
}
