class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_map<int,int>cntmap;
        for(int i=0;i<nums.size();i++){
           // Check if the number exists in the map AND distance is <= k
            if(cntmap.count(nums[i])&& i-cntmap[nums[i]]<=k){
                return true;
            }
            else
             cntmap[nums[i]]=i;;
        }
        return false;  
    }
};