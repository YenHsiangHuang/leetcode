struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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

        if (!n3->next || !n3->next->next) break;
        n1 = n2;
        n2 = n2->next;
        n3 = n2->next;
    }

    delete dummy;
    return head;
}

int main(int argc, const char *argv[]) {

    return 0;
}
