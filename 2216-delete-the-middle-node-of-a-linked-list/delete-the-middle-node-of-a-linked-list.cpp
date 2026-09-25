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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*first=new ListNode(0);
    first->next=head;
    ListNode*fast=head,*prev=first,*slow=head;
    while(fast!= nullptr && fast->next!=nullptr){
        prev->next=slow;
        prev=prev->next;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    return first->next;
        
    }
};