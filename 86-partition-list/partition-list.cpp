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
        if(!head ||!head->next ) return head;
        ListNode*first=new ListNode(0),*second=new ListNode(0);
        
        ListNode*prev=first,*curr=head,*temp=second;
        while(curr){
            if(curr->val<x){
                prev->next=curr;
                prev=prev->next;
                curr=curr->next;
            }
            else{
                temp->next=curr;
                temp=temp->next;
                curr=curr->next;
            }}
           temp->next=nullptr;
           prev->next=second->next;
           head=first->next;
           delete first;
           delete second;
        return head;
    }
};