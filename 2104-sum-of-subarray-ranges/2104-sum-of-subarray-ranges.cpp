class Solution {
public:
    using ll = long long;
    const int mod = 1e9+7;
    
    vector<int> Prv_sm(vector<int>& a){

        int n = a.size() ;
        vector<int> prv_sm(n,-1);
        stack<int> st;
       
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && a[st.top()] >= a[i]) st.pop();
            if(!st.empty()) prv_sm[i] = st.top();
            st.push(i);
        }
        return prv_sm;
    }
    
    vector<int> Nxt_sm(vector<int>& a){

        int n = a.size() ; 
        vector<int> nxt_sm(n,n);
        
        stack<int> st;
       
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && a[st.top()] > a[i]) st.pop();
            if(!st.empty()) nxt_sm[i] = st.top();
            st.push(i);
        }
        return nxt_sm;
    }
    
    vector<int> Prv_lg(vector<int>& a){

        int n = a.size() ; 
        vector<int> prv_lg(n,-1);
        
        stack<int> st;
       
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && a[st.top()] <= a[i]) st.pop();
            if(!st.empty()) prv_lg[i] = st.top();
            st.push(i);
        }
        return prv_lg;
    }
    
    vector<int> Nxt_lg(vector<int>& a){

        int n = a.size() ; vector<int> nxt_lg(n,n);
        stack<int> st;
       
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && a[st.top()] < a[i]) st.pop();
            if(!st.empty()) nxt_lg[i] = st.top();
            st.push(i);
        }

        return nxt_lg;
    }
    
    long long subArrayRanges(vector<int>& a) {
        // 16-12=4
      //1. find sum of largest elements for each subarray
      //2. find sum of smallest elements for each subarray;
      // difference b/w both sums is the range=> ans;

        int n = a.size();
        
        // storing Indices in the vector----
        vector<int> prv_sm = Prv_sm(a);
        vector<int> nxt_sm = Nxt_sm(a);
        vector<int> prv_lg = Prv_lg(a);
        vector<int> nxt_lg = Nxt_lg(a);

        ll sum = 0;
        for(int i = 0 ; i < n ; i++){
            ll p1 = i-prv_sm[i];
            ll q1 = nxt_sm[i]-i;
            ll t1  = p1*q1;
            sum =  sum - 1ll*t1*a[i];
 //       }

   //     ll sum_lg = 0;
   //     for(int i=0 ; i < n ; i++){
            ll p2 = i-prv_lg[i];
            ll q2 = nxt_lg[i]-i;
            ll t2 = p2*q2;
            sum = sum + 1ll*t2*a[i];
        }
   //      cout << sum_lg << endl;
  //       cout << sum_sm << endl;
        return sum;
    }
};