/**
   Some algebra should be done before diving into coding.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return nullptr;

    ListNode *slow = head->next, *fast = head->next->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main(int argc, const char *argv[]) { return 0; }
