class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int r=123-(int)s[i];
            sum=sum+(i+1)*r;
        }
        return sum;
    }
};