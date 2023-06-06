class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
       
        vector<vector<int>> ans;
     if(nums.size() == 0){ return ans; }
    map<vector<int> ,int> map1;
    
        sort(nums.begin() , nums.end());
               int n = nums.size();
        for(int k = 0 ; k < n ;){
           
            int i = k+1;
            int j = n - 1;

            while(i < j){
                int s = nums[i] + nums[j] + nums[k];
                if(s == 0 ){
                    // vector<int> v1;
                    // v1.push_back(nums[i]);
                    // v1.push_back(nums[j]);
                    // v1.push_back(nums[k]);
                //  ans.push_back(v1);
             map1[{nums[i] , nums[j] , nums[k]}] += 1;
         
                    i++;
                //    while(i <  n && nums[i] == nums[i-1]){ i++; }
                    j--;
                 //   while( j >= 0 && nums[j] == nums[j+1]){ j--; }
                    
                }
                else if(s < 0 ){ i++;}
                else if(s > 0 ){j--;}
            }
         k++;
      //  while(k < n && nums[k] == nums[k-1]){ k++; }
        }
    for(auto itr = map1.begin() ; itr != map1.end() ; itr++){
        ans.push_back(itr->first);
    }
    
    
        return ans;
    }
};