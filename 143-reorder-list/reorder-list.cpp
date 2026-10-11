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
        ListNode*slow,*fast;
        slow=fast=head;
        while(fast&& fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode*curr=slow->next;
    slow->next=nullptr;
    ListNode *prev=nullptr;
    ListNode*fut=nullptr;
    while(curr){
        fut=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fut;
    }
    ListNode*head1,*head2;
    head1=head;
    head2=prev;
    while(head2){
ListNode *t1 = head1->next;
            ListNode *t2 = head2->next;

            head1->next = head2;
            head2->next = t1;

            head1 = t1;
            head2 = t2;
    }
    }
};