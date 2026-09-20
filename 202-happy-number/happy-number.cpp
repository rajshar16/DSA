class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int>seen;

        while(n!=1 &&!seen.count(n)){
            seen.insert(n);
            int k=0;
            while(n>0){
                int c=n%10;
            
                k=k+c*c;
                n=n/10;
            }
            n=k;
            
        }
        return n==1;
        
    }
};