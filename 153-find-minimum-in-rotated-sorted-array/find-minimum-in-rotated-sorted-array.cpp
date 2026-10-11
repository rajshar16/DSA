class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int low=0,high=nums.size()-1;
       
        while(low<=high){
             if(nums[low]<=nums[high]) {
                 ans=min(ans, nums[low]); 
                 break;
                 }
            int mid=(low+high)/2;
            //eliminate the sorted half by taking minimum of first elemnt of sorted half and ans
            if(nums[mid]>=nums[low]) {
                ans=min(ans,nums[low]);
               low=mid+1;
                }
                else{
                    ans=min(ans,nums[mid]);
                    high=mid-1;
                }
        }
        return ans;
    }
};