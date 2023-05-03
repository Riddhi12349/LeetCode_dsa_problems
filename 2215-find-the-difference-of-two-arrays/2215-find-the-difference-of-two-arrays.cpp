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

        for(auto itr = map1.begin() ; itr != map1.end() ; itr++){
            if(map2.count(itr->first) == 0){
               ans1.push_back(itr->first);
            }  
        }

         for(auto itr = map2.begin() ; itr != map2.end() ; itr++){
            if(map1.count(itr->first) == 0){
                ans2.push_back(itr->first);
            }
        }
   ans.push_back(ans1);
   ans.push_back(ans2);
   return ans;
    }
    
};