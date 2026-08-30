class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        sort(nums3.begin(),nums3.end());
        sort(nums4.begin(),nums4.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            int    target=-(nums1[i]+nums2[j]);
                int left=0;
                int right=n-1;
                while(left<n && right>=0){
                    long long current=nums3[left];
                    current+=nums4[right];
                    if(current<target){
                        left++;
                    }
                    else if(current>target){
                        right--;
                    }
                   else {
    int leftCount = 1;
    int rightCount = 1;
    
    // Count duplicates in nums3
    while (left + 1 < n && nums3[left] == nums3[left + 1]) {
        leftCount++;
        left++;
    }
    
    // Count duplicates in nums4
    while (right - 1 >= 0 && nums4[right] == nums4[right - 1]) {
        rightCount++;
        right--;
    }
    
    // Multiply the combinations and add to total
    cnt += (leftCount * rightCount);
    
    // Move pointers to the next new numbers
    left++;
    right--;
}
                }

            }
        }
        return cnt;
    }
};