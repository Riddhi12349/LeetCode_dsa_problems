class Solution {
public:
    bool search(vector<int>& a, int target) {
    //         l     m                 h
        //A = [3 ,4, 5, 1 ,2 ,3, 3, 3, 3]
        
       //Array is ROTATED sorted with DUPLICATES    (above)
        int n = a.size();
        int low = 0 , high = n-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(a[mid] == target) return true; 
            
            if(a[mid] == a[low] && a[mid] == a[high]){ 
              //shrink the search space
                low = low+1; high = high-1; 
                continue;
            }
            

            // detecting which part is sorted - left or rt
            
             if(a[low] <= a[mid]){
                 if(target >= a[low] && target < a[mid]){ high = mid-1; }
                 else { low = mid+1; }
             } 
            else{
                if(target > a[mid] && target <= a[high]){ low = mid+1; }
                else { high = mid-1; }
            }
             
        }
        
        return false;
    }
};