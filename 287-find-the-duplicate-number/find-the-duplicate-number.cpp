class Solution {
public:
    int findDuplicate(vector<int>& nums) {
          unordered_set<int>seen;
          int n=0;
          int k =0;

        while(n<nums.size()){
            if(seen.count(nums[n])==0)
            seen.insert(nums[n]);
            else{
                k=n;
                break;
            }
            n++;
        }
            return nums[k];
    }
};