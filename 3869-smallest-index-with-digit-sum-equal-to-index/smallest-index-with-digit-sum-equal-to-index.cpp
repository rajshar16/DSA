class Solution {
    private: 
 int   sumofdigit(int val){
        int sum=0;
        while(val>0){
        sum=sum +val%10;
        val=val/10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=sumofdigit(nums[i]);
            if(nums[i]==i){
                return i;
            }
        }
        return -1;
    }
};