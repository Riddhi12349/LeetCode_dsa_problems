class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    int curday = 0;
    
    StockSpanner() {
        st.push({INT_MAX , 0});
    }
    
    int next(int price) {
     
        curday++;
       
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        
        int prvd = st.top().second;
        st.push({price , curday});
        
        return curday-prvd;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */