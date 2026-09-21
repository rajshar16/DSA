class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
    vector<int>arr;
vector<int>hash(n+1,0);
    for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
    }
    int y,k;
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            k=i;}
            if(hash[i]==2){
                y=i;
            }
    }
    arr.push_back(y);
    arr.push_back(k);
return arr;
    }
};