class Solution {
public:
    
 static bool cmp(string a , string b){
        return a+b > b+a;
    }
    
    string largestNumber(vector<int>& nums) {
      
        vector<string> str_nums;
        for(int i =0 ; i < nums.size() ; i++){
            str_nums.push_back(to_string(nums[i]));
        }
        
       // sorting lexicographically not valid for given qs
        // so we will sort the nos by adding the consecutive nos
        sort(str_nums.begin() , str_nums.end() , cmp);
        
        string ans = "";
        for(int i = 0 ; i < str_nums.size() ; i++){
            ans += str_nums[i];
        }
        if(ans[0]== '0'){
            return "0";
        }
        return ans;
        
    }
};