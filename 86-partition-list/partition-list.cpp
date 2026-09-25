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
        
        vector<ListNode*> nodes;
        
        // 1. Collect nodes < x
        ListNode* temp = head;
        while (temp != nullptr) {
            if (temp->val < x) nodes.push_back(temp);
            temp = temp->next;
        }
        
        // 2. Collect nodes >= x
        temp = head;
        while (temp != nullptr) {
            if (temp->val >= x) nodes.push_back(temp);
            temp = temp->next;
        }
        
        // 3. Relink all nodes in order
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes.back()->next = nullptr; // Crucial to prevent a cycle
        
        return nodes[0];
    }
};