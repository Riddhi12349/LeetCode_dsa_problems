class Solution {
public:      
  /*
           l1 i1
    a1 = [2,4,6,8]
  
           l2 i2
    a2 = [1,7,10,11]
   */     
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2){
        
        // taking smaller size array so binary search works on lesser no of elements , basically
        // to reduce time complexity..
        
        if(a1.size() > a2.size()){
            return findMedianSortedArrays(a2 , a1);
        }
        
        //Assuming a1 size less then a2
        int n1 = a1.size() , n2 = a2.size();
        
        // based on no_of_elements we can have
        // Min = 0 , max = n1  ON THE LEFT SIDE OF ARRAY....
        
        int low = 0 , high = n1;
       
        while(low <= high){
            
            int i1 = (low + high)/2;
            
            int i2 =  (n1 + n2 + 1)/2 - i1;
            
            int l1 = (i1-1 >= 0) ? a1[i1-1] : INT_MIN;
            int l2 = (i2-1 >= 0) ? a2[i2-1] : INT_MIN;
            
            int r1 = (i1 < n1) ? a1[i1] : INT_MAX;
            int r2 = (i2 < n2) ? a2[i2] : INT_MAX;
            
            if(l1 <= r2 && l2 <= r1){
                
                int n = n1+n2;
                
                if(n % 2 == 0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
                
            }
            else if(l2 > r1){
              low = i1 + 1;
            }
            else{
               high = i1 - 1; 
            }
        }
               
               return 0.0;
        
    }
};


 