class Solution {
public:
    using ll = long long;
    
    bool isAchievable(int score , vector<int>& start , int d){
     
        ll n = start.size() , st = start[0];
        
        for(int i = 1 ; i < n ; i++){
            
            st += score;
            if(st > start[i]+d) return false;
            else if(st < start[i]) st = start[i];
        }
        
        return true;
    }
    
    int maxPossibleScore(vector<int>& start, int d) {
          
        sort(start.begin() , start.end());
         
        ll n = start.size() , low = 0 , high = start[n-1]+d-start[0];
        
        int ans = -1;
        
        while(low <= high){
            
            ll mid = (low + high)/2;
            
            if(isAchievable(mid , start , d)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return ans;
        
    }
};