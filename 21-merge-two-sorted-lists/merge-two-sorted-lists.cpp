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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     // create a node intially so that we have not to write the condition to check whether the list is present or not
        ListNode* head = new ListNode(0);
        ListNode* tail=head;
        while(list1 && list2){
            if(list1->val <= list2-> val){
                tail->next=list1;
                list1=list1->next;
                tail=tail->next;
                tail->next= NULL;
            }
            else{
                tail-> next= list2;
                list2 =list2->next;
                tail=tail->next;
                tail-> next=NULL;
            }
        }
            if(list1){
                tail->next=list1;
            }
            else{
                tail->next= list2;
            }

            // delete the first node which we have created 
tail=head;
head=head->next;
delete tail;

return head;
        
    }
};