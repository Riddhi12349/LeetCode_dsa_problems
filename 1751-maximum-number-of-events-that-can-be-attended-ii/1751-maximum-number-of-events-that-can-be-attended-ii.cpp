class Solution {
public:
  int maxValueHelper(int cur_indx ,
  vector<vector<int>>& events , int n , int k ,vector<vector<int>>& dp){

    if(k == 0 || cur_indx >= n){
        return 0;
    }

    if(dp[cur_indx][k] != -1){
      return dp[cur_indx][k];
    }
     
     //** NO NEED TO SEARCH FOR THE NEXT EVENT USING LOOP

    // int i ;
    // for(i = cur_indx + 1 ; i < n ; i++)
    //  if(events[i][0] > events[cur_indx][1])
    //  break;

   //** SINCE SORTING HAS BEEN DONE SO SEARCHING CAN BE DONE USING    BINARY SEARCH
   
   vector<int> temp = {events[cur_indx][1] , INT_MAX , INT_MAX};
   int i = upper_bound(events.begin()+cur_indx+1 ,events.end() , temp)
    - events.begin();
    
    int a1 = events[cur_indx][2] + maxValueHelper(i , events , n , k-1 ,dp);
    int a2 = maxValueHelper(cur_indx + 1 , events, n , k,dp);

    return dp[cur_indx][k] = max(a1 , a2);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();

        vector<vector<int>> dp(n+1, vector<int>(k+1 , -1));
        sort(events.begin() , events.end());

      return   maxValueHelper(0 , events  ,  n , k , dp);
    }
};