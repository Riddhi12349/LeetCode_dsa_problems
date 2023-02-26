class Solution {
public:
    void reverse(vector<int>& nums , int i , int j){
        int t = i , p = j;
        while(t < p){
            swap(nums[t] , nums[p]);
            t++;
            p--;
        }
    }
    void rotate(vector<int>& nums, int k) {
     
    int n = nums.size();
 
    while( k > n ){ k = k - n;}
     
      if(k == 0 || k == n){ return ;}
    
    // for(int i = 0 , j = n-1 ; i < j && j > n-k-1 ; i++ , j--){
    //     swap(nums[i] , nums[j]);
    // }

    reverse(nums , 0 , n-k-1);
    reverse(nums , n-k , n-1);
    reverse(nums , 0 , n-1);
    }
};