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
    ListNode* oddEvenList(ListNode* head) {
       if(!head ||!head->next ) return head;
        ListNode*first=new ListNode(0),*second=new ListNode(0);
       /* int count=0;
        ListNode*temp1=head;
        while(temp1){
            count++;
            temp1=temp1->next;
        }*/
        int i=1;
        
        ListNode*prev=first,*curr=head,*temp=second;
        while(curr){
            if(i %2!=0){
                prev->next=curr;
                prev=prev->next;
                curr=curr->next;
            }
            else{
                temp->next=curr;
                temp=temp->next;
                curr=curr->next;
            }
            i++;
            }
           temp->next=nullptr;
           prev->next=second->next;
           head=first->next;
           delete first;
           delete second;
        return head;   
    }
};