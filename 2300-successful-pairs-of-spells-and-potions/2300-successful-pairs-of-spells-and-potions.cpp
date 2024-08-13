class Solution {
public:
    using ll = long long;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& portions, long long success) {
        
        vector<int> ans; 
        
        int n = portions.size();
        sort(portions.begin() , portions.end());
        
        for(int i = 0 ; i < spells.size() ; i++){
            ll a = spells[i];
            ll b = success/a  + (success % a != 0);
            
            int pos = lower_bound(portions.begin() , portions.end() , b)-portions.begin();
            ans.push_back(n-pos);
        }
    
        return ans;
    }
};