class Solution {
public:
    int ans = INT_MIN;
    void find(vector<string>& arr ,int i , string s){
        
        if(i >= arr.size()){
           ans = max(ans , (int)s.size()) ;
            return;
        }
        
        //not-pick
        find(arr , i+1 , s);
        
        //pick
        //check--
        int f = 0;
        for(int j = 0 ; j < arr[i].size() ; j++){
            if(s.find(arr[i][j]) != string::npos){
                f = 1; break;
            }
        }
        if(f == 0){
            string p = s;
            p += arr[i];
            find(arr , i+1, p);
            
        }
    }
    int maxLength(vector<string>& arr) {
      
        vector<string> v1;
        
        for(int  i = 0 ; i < arr.size() ; i++){
            
            string tmp = arr[i];
            
            vector<int> count(26,0);
            for(int i = 0 ; i < tmp.size() ; i++){
                count[tmp[i]-'a']++;
            }
             int f = 0;
            for(int i = 0 ; i < 26 ; i++){
                if(count[i] > 1){
                    f = 1; break;
                }
            }
            
            if(f == 0){
                v1.push_back(tmp);
            }
            
        }
        find(v1 , 0 , "");
        return ans;
    }
};