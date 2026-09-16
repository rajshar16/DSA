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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* curr= head;
        vector<ListNode*> arr;
        while(curr){
            arr.push_back(curr);
            curr=curr->next;
        }
        int left=0,right=arr.size()-1;
        while(left < right) {
            // Point the left node to the right node
            arr[left]->next = arr[right];
            left++;
        // If they meet in the middle, break early to prevent cycles
            if (left == right) break;
            
            // Point the right node to the next left node
            arr[right]->next = arr[left];
            right--;
    }
    // 3. IMPORTANT: Terminate the last node to prevent cycles!
        arr[left]->next = nullptr;
    }
};