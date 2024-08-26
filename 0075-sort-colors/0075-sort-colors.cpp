class Solution {
public:
    void sortColors(vector<int>& a) {
        
        //POINTS TO REMEMBER
       /*
        0---to---(low-1) = 0
        low---to---(mid-1) = 1
        mid---to---high = unsorted , which we will make eventually sorted
        (high+1) to (n-1) = 2
       */
        
        int n = a.size();
        
        int low=0;
        while(low < n && a[low] == 0){ low++; }
        
        int high= n-1;
        while(high >= 0 && a[high] == 2){ high--; }
        
        int mid=low;
        while(mid <= high){
            
            if(a[mid]==1) mid++;
            else if(a[mid]==0){
                swap(a[mid] , a[low]);
                mid++;
                low++;
            }
            else if(a[mid] == 2){
               swap(a[mid] , a[high]);
               high--;
           }
        }
        
      
    }
};