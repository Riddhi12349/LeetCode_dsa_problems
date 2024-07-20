class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2) {
        
        int n2 = a2.size() , n1 = a1.size();
        vector<int> nxg(n2 , 0);
        
        stack<int> st;
        for(int i=n2-1 ; i>= 0 ; i--){
            
            while(!st.empty() && st.top() <= a2[i]){
                st.pop();
            }
            if(st.empty()){
                nxg[i] = -1;
            }
            else{
                nxg[i] = st.top();
            }
            st.push(a2[i]);
        }
        
        unordered_map <int,int> mp;
        for(int i = 0 ; i < n2 ; i++){
            mp[a2[i]] = nxg[i];
        }
        
        vector<int> ans;
        for(int i = 0 ; i  < n1 ; i++){
            ans.push_back(mp[a1[i]]);
        }
        
        return ans;
    }
};