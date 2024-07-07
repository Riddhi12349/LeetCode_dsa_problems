class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
     //   15 + (15/4 = 3)  + (3 + 3 = 6/4 = 1) + (1 + 2 = 3)
            
       int ans = numBottles;
       
       while(numBottles >= numExchange){
           ans += numBottles/numExchange;
           numBottles = numBottles/numExchange + (numBottles % numExchange);
       }
        
        return ans;
    }
};