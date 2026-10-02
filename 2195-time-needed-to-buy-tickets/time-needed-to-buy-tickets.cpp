class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
     int n=tickets.size();
        queue<int>qu;
        for(int i=0;i<n;i++){
            qu.push(i);
        }
        int time=0;
        while(tickets[k]!=0){
            tickets[qu.front()]--;
            if(tickets[qu.front()]){
                qu.push(qu.front());
            }
            qu.pop();
            time++;
        }
        return time;
    }
};