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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head) return head;
         unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
             st.insert(nums[i]);
        }
        ListNode*prev=new ListNode(0),*curr=head;
        ListNode*temp=prev;
        while(curr){
            if(st.find(curr->val)==st.end()){
               temp->next=curr;
               temp=temp->next;
            }
            curr=curr->next;
        }
        temp->next=nullptr;
        return prev->next;
    }
};