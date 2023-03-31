class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        /*
        vector<int> v2;
        for(int i = 0 ; i < nums.size() ; i++){
            v2.push_back(nums[i]);
        }
        sort(v2.begin() , v2.end());
        int g = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            
            int x = nums[i];
            int j = 0 ;
            while(j < v2.size() && v2[j] <= x){
                j++;
            }
            if(j < v2.size() && v2[j] > x){
                g++;
                v2[j] = INT_MIN;
            }            
        }*/
        
        sort(nums.begin() , nums.end());
        int p1 = 0 , p2 = 1 , g = 0;
    while(p2 != nums.size()){
        if(nums[p2] <= nums[p1]){
            p2++;
        }
        else{
            g++;
            p1++;
            p2++;
        }
    }
        return g;
    }
};