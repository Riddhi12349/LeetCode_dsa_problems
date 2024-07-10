class Solution {
public:
    bool isvalid(int speed , int h , vector<int>& piles){
        
        long long hrsTaken = 0;
        
        for(int i = 0 ; i < piles.size() ; i++){
            long long tot  = piles[i];
           /* while(tot > 0){
                tot -= speed;
                hrsTaken++;
            }*/
            hrsTaken += (tot/speed) ;
            hrsTaken += (tot % speed != 0);
        }
        
        return hrsTaken <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1 , high = *max_element(piles.begin() , piles.end());
        
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(isvalid(mid , h , piles)){ ans = mid;  high = mid-1;}
            else{ low = mid+1; }            
        }
        
        return ans;  
    }
};