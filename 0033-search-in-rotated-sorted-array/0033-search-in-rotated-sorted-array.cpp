class Solution {
public:
    int search(vector<int>& a, int target) {
        
        int n = a.size();
        int low = 0 , high = n-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(a[mid] == target) { return mid; }
            //find=> which part is sorted
            //1. if left sorted
            else if(a[low] <= a[mid]){
                
                if(target >= a[low] && target < a[mid]){ high = mid-1; }
                else{ low = mid+1; }
            }
            //2. if right sorted
            else{
                
                if(target > a[mid] && target <= a[high]){ low = mid+1; }
                else { high = mid-1; }
            }
        }
        
        return -1;
    }
};