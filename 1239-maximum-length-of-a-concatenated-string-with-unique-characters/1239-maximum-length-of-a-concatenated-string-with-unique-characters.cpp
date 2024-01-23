class Solution {
public:
    bool isvalid(string t , string p){
        //t and p should not have a common char
        unordered_map <char,int> mp;
        
        for(auto x : t)
            mp[x]++;
        for(auto x : p){
            if(mp.count(x) > 0) return false;
            mp[x]++;
        }
        //t+p should have unique chars
        for(auto x : mp){
            if(x.second > 1) return false;
        }
        return true;
    }
    int find(vector<string>& a , int i, string prv){
        
        if(i >= a.size()) return 0;
        
        int len=0;
        if(isvalid(a[i],prv)){
            string t = a[i]+prv;
            len = a[i].size() + find(a,i+1,t);
        }
        int len2 = find(a,i+1,prv);
        
        return max(len,len2);
    }
 
    int maxLength(vector<string>& a) {
        return find(a , 0 , "");      
    }
};