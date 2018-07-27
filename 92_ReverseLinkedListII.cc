struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Use only one list to reverse elements. Very clear solution!
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* start = dummy;

    n -= m;
    while (--m > 0)
        start = start->next;  // The position right before reversion.

    ListNode* node = start->next;
    while (n-- > 0) {
        ListNode* toMove = node->next;  // This should go to start->next
        node->next = toMove->next;
        toMove->next = start->next;
        start->next = toMove;
    }

    ListNode* newHead = dummy->next;
    delete dummy;

    return newHead;
}

#if 0
/**
   Use a second list to store reversed list, and then concatenate them after
   reverse works are done.
 */
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head) return nullptr;

    ListNode* dummy1 = new ListNode(0);  // Dummy head for original list
    dummy1->next = head;
    ListNode* start = dummy1;

    n = n - m + 1;
    if (n <= 0) return head;

    while (--m > 0) start = start->next;

    ListNode* dummy2 = new ListNode(0);  // Dummy head for reversed list
    ListNode* dummyTail = nullptr;
    while (n--) {
        ListNode* node = start->next;
        start->next = node->next;
        node->next = dummy2->next;
        dummy2->next = node;
        if (!dummyTail) dummyTail = node;
    }

    if (dummyTail) {  // Concatenate original and reversed lists
        dummyTail->next = start->next;
        start->next = dummy2->next;
    }

    ListNode* newHead = dummy1->next;
    delete dummy1;
    delete dummy2;

    return newHead;
}
#endif

int main(int argc, const char *argv[]) {
    // placeholder
    return 0;
}
