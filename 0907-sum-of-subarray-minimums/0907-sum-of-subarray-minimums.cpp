class Solution {
public:
    const int mod = 1e9+7;
    using ll = long long;
    
    vector<int> findprvNSE(vector<int>& a){
        
        vector<int> prv; stack<int> st;
        
        for(int i = 0 ; i < a.size() ; i++){
            
            while(!st.empty() && a[st.top()] >= a[i]){
                st.pop();
            }
            
            if(st.empty()) prv.push_back(-1);
            else prv.push_back(st.top());
            
            st.push(i);
        }
        
        return prv;
    }
    
    vector<int> findnxtNSE(vector<int>& a){
       
        int  n = a.size();
        stack<int> st;  vector<int> nxt(n , n);

        for(int i = n-1 ; i >= 0 ; i--){
            
            while(!st.empty() && a[st.top()] > a[i]){ st.pop(); }
            
            if(!st.empty()) nxt[i] = (st.top());
            
            st.push(i);
        }
        
        return nxt;
    }
    
    void print(vector<int>& v1){
        
        for(auto x : v1){
            cout << x<< " ";
        }
        cout << endl;
    }
    
    int sumSubarrayMins(vector<int>& a) {
        
        int n = a.size();
        
        vector<int> prvNSE = findprvNSE(a);
        vector<int> nxtNSE = findnxtNSE(a);
        
        print(prvNSE); 
        print(nxtNSE);
        
        ll ans = 0;
        
        for(int i=0 ; i < n ; i++){
            
            ll p = i-prvNSE[i];
            ll q = nxtNSE[i]-i;
            
            ans = (ans + (ll)(p*q*a[i])%mod)%mod;
        }
        
        return ans;
    }
};