class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current number is already in our window, we found a match
            if (window.count(nums[i])) {
                return true;
            }
            
            // Add the current number to the window
            window.insert(nums[i]);
            
            // Keep the window size at most k
            // If we exceed k, remove the oldest element to slide the window forward
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};