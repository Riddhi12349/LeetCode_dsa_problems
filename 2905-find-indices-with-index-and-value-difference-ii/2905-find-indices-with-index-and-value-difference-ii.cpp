class Solution {
public:
//    #define pair<int,int>  P;
    
    vector<int> findIndices(vector<int>& nums, int indxDiff, int valDiff) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > min_pq;
    
        priority_queue<pair<int,int>> mx_pq;
        
        
        int i = 0 , n = nums.size() ; 
        
        while( i <= n-indxDiff-1 ){
            min_pq.push({nums[i] , i}); mx_pq.push({nums[i] , i});
            i++;
        }
        
        
        for(int j = n-1 ; j >= indxDiff ; j--){
           
            int  mn_ele = min_pq.top().first , mn_indx = min_pq.top().second;
            
            int mx_ele = mx_pq.top().first  , mx_indx = mx_pq.top().second;
            
            int d1 = abs(mn_ele - nums[j]) , d2 = abs(mx_ele - nums[j]);
            
            if(d1 >= valDiff) return {mn_indx , j};
            else if(d2 >= valDiff) return  {mx_indx , j};
            else{
               if(min_pq.top().second >= j-indxDiff) min_pq.pop();
               if(mx_pq.top().second >= j-indxDiff) mx_pq.pop();
      
            }
        }
        
        return {-1,-1};
    }
};