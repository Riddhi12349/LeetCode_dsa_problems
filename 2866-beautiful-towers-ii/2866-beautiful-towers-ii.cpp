class Solution {
public:
    using ll = long long;
    
    void print(vector<ll>& a){
        for(auto i : a)
            cout << i << " ";
        cout << endl;
    }
    vector<ll> findNxt(vector<int>& mxHts){
        
        int n = mxHts.size();
       
        vector<ll> suff(n,0); 
       
        stack<pair<ll,ll>> st;
        st.push({mxHts[n-1] , n-1});
        
        for(int j = n-2 ; j >= 0 ; j--){
            
            while(!st.empty()
                  && st.top().first >= mxHts[j]) 
                st.pop();
            
            if(st.empty()){
                suff[j] = (ll)(n-1-j)*mxHts[j];
            }
            else{
                ll t = st.top().second - j - 1;
                if(t == 0)
                    suff[j] = mxHts[j+1] + suff[j+1];
                else{
                    suff[j] = t*mxHts[j]+suff[st.top().second] + st.top().first;
               }
            }

             st.push({mxHts[j] , j}); 
        }
        
        return suff;
    }
    
    vector<ll> findPrv(vector<int>& mxHts){
        
        int n = mxHts.size();
       
        vector<ll> pref(n,0); 
       
        stack<pair<ll,ll>> st;
        st.push({mxHts[0] , 0});
        
        for(int j = 1 ; j < n ; j++){
            
            while(!st.empty() && st.top().first >= mxHts[j]) 
                st.pop();
            
            if(st.empty()){
                pref[j] = (ll)(j)*mxHts[j];
            }
            else{
                ll t = j-st.top().second - 1;
                if(t == 0)
                     pref[j] = mxHts[j-1] + pref[j-1];
                else{
                   pref[j] = t*mxHts[j]+pref[st.top().second]+ st.top().first;
                 }
            }

             st.push({mxHts[j] , j}); 
        }
        
        return pref;
    }
    
        
    long long maximumSumOfHeights(vector<int>& mxHts){
        
     vector<ll> nxt =   findNxt(mxHts);
     vector<ll> prv =   findPrv(mxHts);
        
      //  print(nxt); print(prv);
        
        ll mxSum = 0; int n = mxHts.size();
        for(int i = 0 ; i < n ; i++){
            
           ll sum = mxHts[i];
           sum += prv[i];
           sum += nxt[i];
            
            mxSum = max(mxSum , sum);
        }
        
        return mxSum;
    }
};