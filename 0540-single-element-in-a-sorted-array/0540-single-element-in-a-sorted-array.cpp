class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        
        int n = a.size();
        int low = 0 , high = n-1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            if(mid+1 < n && a[mid] == a[mid+1]){
                int len = high-mid+1;
                if(len % 2 != 0){ low = mid+2; }
                else { high = mid-1; }
            }
            else if(mid-1 >= 0 && a[mid]==a[mid-1]){
                int len = mid-low+1;
                if(len % 2 != 0){ high = mid-2; }
                else{ low = mid+1; }
            }
           else{
               return a[mid];
           }
        }
        
        return -1;
    }
};