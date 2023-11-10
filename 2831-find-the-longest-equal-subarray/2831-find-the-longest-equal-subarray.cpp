class Solution {
public:
    int b_search(vector<int>& v1 , int k , int l){
        // indexes =  [0,2,4,7,13]
        int low = l , high = v1.size()-1 , ans = 1;
        while(low <= high){
             int mid = (low + high)/2;
             int del = (v1[mid]-v1[l]+1)-(mid-l+1);
             if(del <= k){
                 ans = mid-l+1;
                 low = mid+1;
             }
             else{
                high = mid-1;
             }
        }

        return ans;
    }
    int longestEqualSubarray(vector<int>& a, int k) {
        
        unordered_map<int,vector<int>> mp;
        for(int i = 0 ; i < a.size() ; i++){
            mp[a[i]].push_back(i);
        }

        int mxlen = 0;
        for(auto x : mp){
            vector<int> v1 = x.second;
            for(int low = 0 ; low < v1.size() ; low++){
            int len = b_search(v1 , k , low);
            mxlen = max(mxlen , len); 
           }
        }

        return mxlen;
    }
};