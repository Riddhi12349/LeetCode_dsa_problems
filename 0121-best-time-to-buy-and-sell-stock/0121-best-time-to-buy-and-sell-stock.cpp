class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int val = 0;
        int n = prices.size();

      //  stack<int> st;
      int min = prices[0];
      //  st.push(prices[0]);

        for(int i = 1 ; i < n ;i++){
            if(prices[i] < min){
               // st.pop();
               // st.push(prices[i]);
               min = prices[i];
            }
            else{
               // val = prices[i]-st.top();
               val = prices[i]-min;
                if(val > profit){
                    profit = val;
                }
            }
        }
        return profit;
    }
};