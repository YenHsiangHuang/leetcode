struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// A concise way that replaces dummy head with a double ptr, by StefanPochman
ListNode *swapPairs(ListNode *head) {
    ListNode **npp = &head;  // Used to store the previous->next
    ListNode *n1, *n2;
    while ((n1 = *npp) && (n2 = n1->next)) {
        n1->next = n2->next;
        n2->next = n1;
        *npp = n2;
        npp = &(n1->next);
    }
    return head;
}

#if 0
// Eliminate redundant n4
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *n1 = dummy, *n2 = head, *n3 = head->next;
    head = n3;
    while (true) {
        n2->next = n3->next;
        n3->next = n2;
        n1->next = n3;

        if (!n2->next || !n2->next->next) break;
        n1 = n2;
        n2 = n2->next;
        n3 = n2->next;
    }

    delete dummy;
    return head;
}
#endif

#if 0
// Original solution
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *n1 = dummy, *n2 = head, *n3 = head->next, *n4 = n3->next;
    head = n3;
    while (true) {
        n1->next = n3;
        n2->next = n4;
        n3->next = n2;

        if (!n4 || !n4->next) break;
        n1 = n2;
        n2 = n4;
        n3 = n4->next;
        n4 = n3->next;
    }

    delete dummy;
    return head;
}
#endif


int main(int argc, const char *argv[]) {

    return 0;
}
