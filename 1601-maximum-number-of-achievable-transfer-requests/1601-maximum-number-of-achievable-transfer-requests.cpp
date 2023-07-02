class Solution {
public:
  int ans = 0;
    void helper(int n , int indx , vector<vector<int>>& req , vector<int>& temp , int l ){
     
     //base case ----
     if(indx == req.size()){
         for(auto r : temp) {
             if(r != 0) return;
         }
         ans = max(ans ,l);
         return;
     }
        
     // req not accepted
       helper(n , indx + 1 ,  req , temp , l);
       // req accepted
       temp[req[indx][0]]--;
       temp[req[indx][1]]++;
       helper(n , indx + 1 , req , temp , l+1);

       // vapas aate hue combat the changes
       temp[req[indx][0]]++;
       temp[req[indx][1]]--;

    }
    int maximumRequests(int n, vector<vector<int>>& req) {
        // n is no of buildings
        int indx = 0;
        vector<int> temp(n , 0);
        int no_of_req_accepted = 0;
        helper(n ,indx , req , temp  , no_of_req_accepted);
        ans = max(ans , no_of_req_accepted);
        return ans;
    }
};