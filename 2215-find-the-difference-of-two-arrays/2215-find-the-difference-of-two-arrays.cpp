class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> ans;
        unordered_map<int,int> map1 , map2;
        vector<int> ans1 , ans2;
      
        for(int i = 0 ; i < nums1.size() ; i++){
            map1[nums1[i]] += 1;
        }
        for(int i = 0 ; i < nums2.size() ; i++){
            map2[nums2[i]] += 1;
        }
     sort(nums1.begin() , nums1.end());
     sort(nums2.begin() , nums2.end());

        for(int i = 0 ; i < nums1.size() ; i++){
            if(map2.count(nums1[i]) == 0){
                if(i == 0){
                    ans1.push_back(nums1[i]);
                }
                else{
                if(nums1[i] != nums1[i-1]){
                      ans1.push_back(nums1[i]);
                }
           }
            }  
        }

         for(int i = 0 ; i < nums2.size() ; i++){  
            if( map1.count(nums2[i]) == 0){
                if(i == 0){
                      ans2.push_back(nums2[i]);
                }
                else{
                 if(nums2[i] != nums2[i-1])  {
                     ans2.push_back(nums2[i]);
                 }
              }
            }
        }
   ans.push_back(ans1);
   ans.push_back(ans2);
   return ans;
    }
    
};