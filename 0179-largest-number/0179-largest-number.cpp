class Solution {
public:
    static bool cmp(string s1 , string s2){
        
       int n1 = s1.size() , n2 = s2.size(); 
      
    if(n1==n2){
       int i=0;
       while(i < n1 && i < n2){
           if(s1[i]==s2[i]){ i++; }
           else if(s1[i]>s2[i]){ return true; }
           else return false;
       }
    }
    else {
         return (s1+s2)>(s2+s1);
        }
        return true;
    }
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> v1;
        
        int f=0;
        for(int i = 0 ; i < nums.size() ; i++){
            
            //check if nums->contains only zeros
            if(nums[i] != 0) f=1;
            v1.push_back(to_string(nums[i]));
        }
        
        if(f==0){
            //means nums contains only string "0"
            return "0";
        }
        
        sort(v1.begin() , v1.end() , cmp); // descending order acc to digit pos
        
        
        string ans = "";
        for(int i = 0 ; i < v1.size() ; i++){
            ans += v1[i];
        }
        /*
        int i=0;
        while(i<ans.size()){
            if(ans[i]=='0') i++;
            else break;
        }
        
        ans = ans.substr(i);
        return ans.size()==0 ? "0" : ans;
        */
        return ans;
    }
};