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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //create new link list
        ListNode* dummyhead=new ListNode(0);
        //point the new linklist
        ListNode* current=dummyhead;
          int carry=0;


          // Continue if there are nodes left in either list, OR if there's a leftover carry
        while(l1 != nullptr  || l2 !=nullptr || carry!=0) {
          int x= (l1!= nullptr)? l1-> val :0;
          int y= (l2!= nullptr)? l2-> val :0;


        int digit=x +y +carry;
        carry=digit/10;


        // Create a new node with the current digit
        current->next = new ListNode(digit % 10);
            current = current->next;
// Advance the pointers if they aren't null
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        ListNode* result = dummyhead->next;
        delete dummyhead; // Free the dummy node memory
        return result;
        
    }
};