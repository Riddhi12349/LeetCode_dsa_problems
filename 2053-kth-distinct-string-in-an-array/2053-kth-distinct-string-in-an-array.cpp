class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map <string,int> mp;
        
        for(auto s : arr){
            mp[s]++;
        }
           
        string ans = "";
        
        for(int i = 0 ; i < arr.size() && k > 0; i++){
            if(mp[arr[i]] == 1){
                ans = arr[i];
                k--;
            }
        }
        
      
     if(k == 0)   
        return ans;
        
     return "";
        
    }
};