struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* l1, ListNode* l2) {
    if (l1->val > l2->val) std::swap(l1, l2);  // Make l1 smaller
    ListNode *node = l1;
    ListNode *n1 = l1->next;
    ListNode *n2 = l2;
    while (n1 && n2) {  // Both are non-empty
        if (n1->val < n2->val) {
            node->next = n1;
            n1 = n1->next;
        } else {
            node->next = n2;
            n2 = n2->next;
        }
        node = node->next;
    }

    if (n1) node->next = n1;
    else    node->next = n2;

    return l1;
}

// Let's try merge sort!
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    // Find middle point
    ListNode *n1 = head, *n2 = head->next->next;
    while (n2 && n2->next) {
        n1 = n1->next;
        n2 = n2->next->next;
    }

    // Sort slow and slow->next
    ListNode* head2 = sortList(n1->next);
    n1->next = nullptr;
    head = sortList(head);
    if (!head2) return head;

    return merge(head, head2);
}

int main(int argc, const char *argv[]) {

    return 0;
}
