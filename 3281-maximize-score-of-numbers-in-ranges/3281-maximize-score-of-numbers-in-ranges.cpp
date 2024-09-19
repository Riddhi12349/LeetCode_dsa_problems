class Solution {
public:
    bool isPossible(int diff , vector<int>& start , int d){
        
        long long st = 0, n = start.size(); 
        
      //  start = [0,3,6] , d =2 ; diff=3 st=0+3+3
        
        for(int i = 0 ; i < n ; i++){
            
            st = max(st , (long long)start[i]);
            
            if(st >  start[i]+d){
                return false;
            }
            
            st += diff;
        }
        
        return true;
    }
    
    int maxPossibleScore(vector<int>& start, int d) {
        
        sort(start.begin() , start.end());
        
        int n = start.size();
        
        long long low = 0 , high = start[n-1]+d+2  , ans = -1;
        
        while(low <= high){
            
            long long mid = (low + high)*1ll/2;
            
            if(isPossible(mid , start , d)){
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