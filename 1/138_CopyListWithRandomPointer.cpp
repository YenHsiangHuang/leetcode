/**
   Definition for singly-linked list with a random pointer.
 */
#include <unordered_map>
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

RandomListNode* copyRandomList(RandomListNode* head) {
    if (!head) return nullptr;

    for (auto l1 = head; l1 != nullptr; l1 = l1->next->next) {
        auto l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
    }

    for (auto l1 = head; l1 != nullptr; l1 = l1->next->next) {
        if (l1->random != nullptr) l1->next->random = l1->random->next;
    }

    auto newHead = head->next;
    for (auto l1 = head; l1 != nullptr; l1 = l1->next) {
        auto l2 = l1->next;
        l1->next = l2->next;
        if (l2->next != nullptr) l2->next = l2->next->next;
    }

    return newHead;
}

int main(int argc, const char* argv[]) {
    // placeholder
}
