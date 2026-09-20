class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1; // Since array size is n + 1, max value is n
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            
            // Count how many numbers are less than or equal to mid
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            
            // If count exceeds mid, the duplicate is in the lower half
            if (count > mid) {
                high = mid;
            } 
            // Otherwise, it's in the upper half
            else {
                low = mid + 1;
            }
        }
        
        // low and high converge to the duplicate number
        return low; 
    }
};