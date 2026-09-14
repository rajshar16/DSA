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
// method 1 using the array
if (head == nullptr) return nullptr; // Handle empty list
vector<int> arr;
arr.push_back(head->val);
ListNode* curr=head->next;
while(curr){
    if(arr[arr.size()-1]!=curr-> val){
        arr.push_back(curr->val);}
        curr=curr->next;
    
    }
    curr=head;
    int index=0;
    while(index<arr.size()){
        curr->val=arr[index];
        curr=curr->next;
        index++;
    }
    int size=arr.size()-1;
    curr=head;
    while(size--){
        curr=curr->next;
    }

    
    curr->next= nullptr;
return head;
}
    
};