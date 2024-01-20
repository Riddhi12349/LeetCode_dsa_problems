class Solution {
public:
    const int mod = 1e9+7;
    
    int sumSubarrayMins(vector<int>& a) {
        
        int sum = 0 ;
        int n = a.size();
        stack<pair<int,int> > st; 
        vector<int> ans(n,0);
        
        for(int i = n-1 ;  i >= 0 ; i--){
             
            while(!st.empty() && st.top().first > a[i])
                st.pop();
            
            if(!st.empty()){
            int indx = st.top().second;
            int t = (ans[indx] + a[i]*(indx-i))%mod;
            ans[i] = t;}
            else{
                ans[i] = (a[i]*(n-i))%mod;
            }
            
            st.push({a[i],i});
        }
        
        for(auto x : ans){
            sum += x;
            sum = sum % mod;
        }
        return sum%mod;
    }
};