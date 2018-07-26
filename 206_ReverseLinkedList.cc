struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Better solution: no input check, less operation.
ListNode* reverseList(ListNode* head) {
    ListNode* prevNode = nullptr;
    while (newHead) {
        ListNode* tmp = head->next;
        head->next = prevNode;
        prevNode = head;
        head = tmp;
    }
    return prevNode;
}

// My original solution requires input check, and use more operations.
ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;

    ListNode *node = head->next;
    ListNode *newHead = head;
    while (node) {
        head->next = node->next;
        node->next = newHead;
        newHead = node;
        node = head->next;
    }
    return newHead;
}

int main(int argc, const char *argv[]) {
    // placeholder
    return 0;
}
