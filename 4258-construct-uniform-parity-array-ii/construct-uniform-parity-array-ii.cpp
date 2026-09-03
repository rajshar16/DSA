class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]<mini) mini=nums1[i];
             }
if(mini%2!=0){
     return true;
     }
     else{
    for(int i=0;i<nums1.size();i++){
        if(nums1[i]%2!=0) return false;
    }
}
return true;;
        }
    
};