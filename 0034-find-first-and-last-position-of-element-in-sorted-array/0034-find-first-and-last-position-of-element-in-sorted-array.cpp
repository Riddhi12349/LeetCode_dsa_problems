class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        
        //implementing w/o using lower_bound and upper_bound
        int n  = a.size();
        
        int f = -1 , l = -1;
        
        //finding first index
        int low = 0 , high = n-1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            if(a[mid] == target){ f = mid; high = mid-1; }
            else if(a[mid] > target) { high = mid-1; }
            else { low = mid+1;  } 
        }
        
        //finding last index
        low = 0 , high = n-1;
        while(low <= high){
            
            int mid = (low + high)/2;
            if(a[mid] == target){ l = mid; low = mid+1; }
            else if(a[mid] > target){ high = mid-1; }
            else { low = mid+1 ; }
        }
        
        if(f == -1){ return {-1, -1}; }
        
        return {f,l};
        
    }
};