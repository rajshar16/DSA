class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp; 
        
        for (int num : nums) {
            
            if (mpp.count(num) > 0) {
                return num;
            }
            
            mpp[num]++;
        }
        
        return -1; 
    }
};