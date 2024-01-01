class Solution {
public:
   // g=[4,6,8,10,12]
   // s=[1,2,4,6,8,10]
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        
        int ans = 0; 
        
        for(int i = 0 , j = 0 ; i < g.size() && j < s.size() ; j++){
            if(s[j] >= g[i]) {ans++; i++; }
        }
        
        return ans;
    }
};