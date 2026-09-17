class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        const int INF = 1e9; // Use a large number to represent infinity
        
        vector<int> prefix(n, INF);
        vector<int> suffix(n, INF);
        
        // 1. Build the prefix array using a sliding window
        int sum = 0, left = 0;
        int min_len = INF;
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                min_len = min(min_len, right - left + 1);
            }
            prefix[right] = min_len;
        }
        
        // 2. Build the suffix array using a sliding window from right to left
        sum = 0;
        int right_ptr = n - 1;
        min_len = INF;
        for (int i = n - 1; i >= 0; --i) {
            sum += arr[i];
            while (sum > target && right_ptr >= i) {
                sum -= arr[right_ptr];
                right_ptr--;
            }
            if (sum == target) {
                min_len = min(min_len, right_ptr - i + 1);
            }
            suffix[i] = min_len;
        }
        
        // 3. Find the minimum sum of lengths for two non-overlapping sub-arrays
        int ans = INF;
        for (int i = 0; i < n - 1; ++i) {
            if (prefix[i] != INF && suffix[i + 1] != INF) {
                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }
        
        return ans == INF ? -1 : ans;
    
    }
};