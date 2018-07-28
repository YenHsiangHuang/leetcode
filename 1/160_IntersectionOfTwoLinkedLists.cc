struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    int lenA = 1, lenB = 1;
    ListNode *tailA = headA;
    ListNode *tailB = headB;
    while (tailA->next != nullptr) {
        tailA = tailA->next;
        lenA++;
    }
    while (tailB->next != nullptr) {
        tailB = tailB->next;
        lenB++;
    }
    if (tailA != tailB) return nullptr;

    int cut = lenA - lenB;
    ListNode *node1 = headA, *node2 = headB;
    if (cut < 0) {  // Set node1 be the head of longer list
        node1 = headB;
        node2 = headA;
        cut = -cut;
    }
    while (cut > 0) {
        node1 = node1->next;
        cut--;
    }
    while (node1 != node2) {
        node1 = node1->next;
        node2 = node2->next;
    }
    return node1;
}

int main(int argc, const char *argv[]) { return 0; }
