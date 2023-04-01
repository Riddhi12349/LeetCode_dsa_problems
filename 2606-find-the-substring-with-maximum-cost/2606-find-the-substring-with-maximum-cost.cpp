class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        unordered_map<char , int> fmap;
        for(int i = 0 ; i < chars.size() ; i++){
            fmap[chars[i]] = vals[i];
        }
        
        vector<int> v2(s.size()+1 , 0);
        for(int i = 0 ; i < s.size() ; i++){
            if(fmap.count(s[i]) > 0){
                v2[i+1] = max(fmap[s[i]] , fmap[s[i]] + v2[i]);
            }
            else{
                int t = s[i]-96;
                v2[i+1] = max(t , t + v2[i]);
            }
        }
        
      int maximum = INT_MIN;
        for(int i = 0 ; i < v2.size() ; i++){
            if(maximum < v2[i]){
                maximum = v2[i];
            }
        }

        return maximum;
    }
};