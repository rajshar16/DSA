class Solution {
public:
    int addDigits(int num) {
        int sum=(num/10)+(num%10);
        while(sum>=10){
            sum=(sum/10)+(sum%10);
        }
        return sum;
    }
};