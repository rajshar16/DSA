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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> output = {-1, -1};
        
        // If the list has fewer than 3 nodes, there can't be any critical points
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return output;
        }

        // Set up pointers
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        // Track positions
        int index = 1; 
        int firstCriticalIndex = 0;
        int prevCriticalIndex = 0;

        // Loop as long as there is a valid 'next' node
        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;
            
            // Check for local maxima or minima
            bool isLocalMaxima = (curr->val > prev->val) && (curr->val > nextNode->val);
            bool isLocalMinima = (curr->val < prev->val) && (curr->val < nextNode->val);

            if (isLocalMaxima || isLocalMinima) {
                if (firstCriticalIndex == 0) {
                    // This is the first critical point we've encountered
                    firstCriticalIndex = index;
                    prevCriticalIndex = index;
                } else {
                    // This is at least the second critical point we've seen
                    int currentDistance = index - prevCriticalIndex;
                    
                    // Update Minimum Distance (output[0])
                    if (output[0] == -1) {
                        output[0] = currentDistance;
                    } else {
                        output[0] = min(output[0], currentDistance);
                    }
                    
                    // Update Maximum Distance (output[1])
                    // Always the distance between the current point and the very first point
                    output[1] = index - firstCriticalIndex;
                    
                    // Update the previous critical point to the current one
                    prevCriticalIndex = index;
                }
            }

            // Shift all pointers forward by one step
            prev = curr;
            curr = nextNode;
            index++;
        }

        return output;
    }
};