class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      vector<int>arr;  
            map<int,int> mpp;
 for(auto it = nums.begin(); it != nums.end(); it++){    
            mpp[*it]++;
        }
      
   for(auto it = mpp.begin(); it != mpp.end(); it++){
           
            if(it->second==1){
                arr.push_back(it->first); 
            }
    }
    return arr;
    
    }
};