class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        
        int hash[10005] = {0}; 
        
        for(int i = 0; i < n; i++){
            hash[nums[i]]++; 
        }
        
        int y, k;
        for(int i = 1; i <= n; i++){
            if(hash[i] == 0){
                k = i; 
            }
            if(hash[i] == 2){
                y = i; 
            }
        }
     return {y, k}; 
    }
};   
        