class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0; 
        for (int i=0;i< nums.size();i++) {
            xorr ^= nums[i];
        }

        // Isolate the rightmost set bit. 
        // Using long long prevents overflow with INT_MIN (-2147483648)
        long long diff_bit = xorr & (-xorr);

        int num1 = 0;
        int num2 = 0;

        // Partition the array into two groups based on the distinguishing bit
        for (int i=0;i<nums.size();i++) {
            if (nums[i] & diff_bit) {// check true or false
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }

        return {num1, num2};
    }
};