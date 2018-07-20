struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return false;
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main(int argc, const char *argv[]) { return 0; }
