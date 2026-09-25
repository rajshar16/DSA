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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode*first=new ListNode(0);
        first->next=head;
        head=first;
        ListNode*curr=first->next , *prev=first;
        while(curr!=nullptr){
            if(curr->next!=nullptr && curr->val==curr->next->val){
                int k=curr->val;
                
                while(curr!=nullptr &&curr->val==k){
                    curr=curr->next;
                }
                prev->next=curr;
            }
                else{
                      prev= curr;
                curr=curr->next;
                
            }  
        }
        ListNode*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
};