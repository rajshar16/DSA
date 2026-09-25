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
        if (!head) return nullptr;
        
        vector<int> less_val;
        vector<int> greater_val;
        
        // 1. Separate values into two vectors
        ListNode* temp = head;
        while (temp != nullptr) {
            if (temp->val < x) {
                less_val.push_back(temp->val);
            } else {
                greater_val.push_back(temp->val);
            }
            temp = temp->next;
        }
        
        // 2. Overwrite the linked list with partitioned values
        temp = head;
        for (int val : less_val) {
            temp->val = val;
            temp = temp->next;
        }
        for (int val : greater_val) {
            temp->val = val;
            temp = temp->next;
        }
        
        return head;
    }
};