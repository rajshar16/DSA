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
    bool isPalindrome(ListNode* head) {
        ListNode*temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        count =count/2;
        ListNode*curr=head,*prev=nullptr;
        if(head->next==nullptr) return true;
        while(count--){
            prev=curr;
            curr=curr->next;
        }
       prev->next=nullptr;
       prev=nullptr;
        temp=nullptr;
        while(curr){
          temp=  curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp; 
        }
        ListNode*head2=prev,*head1=head;
        while(head1){
            if(head1->val!=head2->val) return 0;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};