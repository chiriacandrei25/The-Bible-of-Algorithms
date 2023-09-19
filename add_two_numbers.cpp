class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        auto node1 = list1, node2 = list2;
        auto head = new ListNode(), tail = head;
        int carry = 0;
        while (node1 || node2 || carry) {
            int digitSum = carry;
            if (node1) {
                digitSum += node1->val;
                node1 = node1->next;
            }
            if (node2) {
                digitSum += node2->val;
                node2 = node2->next;
            }
            carry = digitSum > 9;
            digitSum %= 10;
            tail->next = new ListNode(digitSum);
            tail = tail->next;
        }
        return head->next;
    }
};

