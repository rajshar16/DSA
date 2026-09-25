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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
ListNode* tempCount = head;
while (tempCount) {
    count++;
    tempCount = tempCount->next;
}
       ListNode*first=new ListNode(0);
       first->next=head;
       head=first;

       while(count>=k){
        int n=k;
       ListNode*second=first->next;
       ListNode*prev=first;
       ListNode*curr=first->next;
       ListNode*front;
       while(n){
        front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
        n--;
       } 
       first->next=prev;
       second->next=curr;
      first=second;
      count-=k;
       }
       ListNode*temp=head;
       head=head->next;
       delete temp;
       return head;
    }
};