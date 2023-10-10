class Solution {
public:
    using ll = long long;
    int dp[502][502];

    ll find(vector<int>& a,vector<int>& b , int i , int j){
        
        if(i >= a.size() || j >= b.size()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];
        
        ll op1 = a[i]*b[j] + find(a , b , i+1 , j+1);
        ll op2 =  find(a , b , i , j+1);
        ll op3 =  find(a , b , i+1 , j);
 //       ll op4 =  find(a , b , i+1 , j+1);

   //     return max(op1 , max(op2 , max(op3, op4)));
        return dp[i][j] = max(op1 , max(op2 , op3));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {  
      
      memset(dp , -1, sizeof(dp));

      int ans =  find(nums1 , nums2, 0 , 0);
     
      if(ans == 0){
          int mx1 = *max_element(nums1.begin() , nums1.end());
          if(mx1 > 0){
          int mx2 = *max_element(nums2.begin() , nums2.end());
          ans = mx1*mx2;
          }
          else{
           int mn2 = *min_element(nums2.begin() , nums2.end());
           ans = mx1*mn2;
          }
      }
      
      return ans;
    }
};