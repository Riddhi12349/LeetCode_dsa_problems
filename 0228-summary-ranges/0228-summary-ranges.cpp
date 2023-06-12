class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size(); 
       vector<string> ans;
       if(n == 0){
           return ans;
       }
        int t = nums[0]; //0
        int p = t; //0
    for(int i = 1 ; i < n ;i++){
  
     if(nums[i] == t+1){ //7==6
             t = nums[i];//7
         }
     else{
        string s;

         if(p != t){
          s = to_string(p) + "->" + to_string(t);
        }

        else{
          s = to_string(p);
        }

       ans.push_back(s);
       p = nums[i]; //4
       t = p;//4
         }
        }
         
    string s;

    if(p != t){
         s = to_string(p) + "->" + to_string(t);
     }
     else{
          s = to_string(p);
     }

         ans.push_back(s);

        return ans;
    }
};