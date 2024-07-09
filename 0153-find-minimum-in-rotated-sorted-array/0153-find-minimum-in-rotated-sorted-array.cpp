class Solution {
public:
    int findMin(vector<int>& a) {
        
        int mn = INT_MAX , n = a.size();
        
        int low = 0 , high = n-1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            //find which part is sorted => left or rt
            
            if(a[low] <= a[mid]){
                mn = min(mn , a[low]);
                low = mid+1;
            }
            else{
                mn = min(mn , a[mid]);
                high = mid-1;
            }
        }
        
        return mn;
    }
};