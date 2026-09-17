class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // min_len[i] will store the minimum length of a valid sub-array 
        // found so far up to index i.
        vector<int> min_len(n, INT_MAX / 2); 
        
        int left = 0, sum = 0;
        int ans = INT_MAX;
        int best_so_far = INT_MAX / 2;
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Shrink the window if the sum exceeds the target
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            
            // When we find a valid sub-array
            if (sum == target) {
                int current_length = right - left + 1;
                
                // If there's a non-overlapping valid sub-array before the current one,
                // add its minimum length to our current length and update the answer.
                if (left > 0) {
                    ans = min(ans, current_length + min_len[left - 1]);
                }
                
                // Update the best minimum length found so far
                best_so_far = min(best_so_far, current_length);
            }
            
            // Record the best minimum length ending at or before 'right'
            min_len[right] = best_so_far;
        }
        
        return ans >= INT_MAX / 2 ? -1 : ans;
    
    }
};