class Solution {
public:
    int nthUglyNumber(int n) {
        
        set<long long> st1 , st_ans;
        
        st1.insert(1);
        
        while(st_ans.size() < n){
          
            auto it = st1.begin();
            long long fr = *it;
            st1.erase(it);
            
            st_ans.insert(fr);
            
            st1.insert(fr*2);
            st1.insert(fr*3);
            st1.insert(fr*5);
            
        }
        
        
        auto it = --st_ans.end();
        return *it;
        
    }
};