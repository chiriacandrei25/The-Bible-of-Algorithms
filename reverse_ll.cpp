struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        auto prev = head;
        auto node = head->next;
        head->next = nullptr;
        while (node) {
            auto nextNode = node->next;
            node->next = prev;
            prev = node;
            node = nextNode;
        }
        return prev;
    }
};

