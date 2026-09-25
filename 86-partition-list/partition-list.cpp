/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode *lessHead = nullptr, *lessTail = nullptr;
        ListNode *greaterHead = nullptr, *greaterTail = nullptr;

        while (head) {
            if (head->val < x) {
                if (!lessHead) {
                    lessHead = lessTail = head;
                } else {
                    lessTail->next = head;
                    lessTail = lessTail->next;
                }
            } else {
                if (!greaterHead) {
                    greaterHead = greaterTail = head;
                } else {
                    greaterTail->next = head;
                    greaterTail = greaterTail->next;
                }
            }
            head = head->next;
        }

        // Terminate the >= x list to prevent cycles
        if (greaterTail) {
            greaterTail->next = nullptr;
        }

        // If there are no nodes < x, return the >= x list directly
        if (!lessHead) {
            return greaterHead;
        }

        // Connect the two partitions
        lessTail->next = greaterHead;
        return lessHead;
    }
};