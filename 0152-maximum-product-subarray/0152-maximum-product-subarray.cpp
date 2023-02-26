

class Solution {
public:
    int Product(vector<int>& nums , int l , int h) {
     
       
        int p = 1 , cnt = 0;
        int maxp = INT_MIN;
     
        for(int i = l ; i <= h ; i++){
           if(nums[i] < 0){ cnt++; }
         
            p = p * nums[i]; 
            maxp = max(maxp , p); 
          
        }

        if(cnt % 2 == 0){
       return maxp;
             }
        else{
            int p1 = 1 , p2 = 1 , maxp1 = INT_MIN , maxp2 = INT_MIN;
            int i = l;
            while(nums[i] > 0){
                i++;
            }
            i = i+1;
            for( ; i <= h ; i++){
                p1 *= nums[i];
                maxp1 = max(maxp1 , p1);
            }

            int j = h;
            while(nums[j] > 0){
                j--;
            }
            j= j-1;
            for( ; j>= l ;j--){
                p2 *= nums[j];
                maxp2 = max(maxp2 , p2);
            }

            return max(maxp1 , maxp2);
        }
    }
    int maxProduct(vector<int>& nums){
      
       int n = nums.size();
        if(n == 1){ return nums[0]; }

        int maxp = INT_MIN;
        int i = 0 , j = 0;
        for( ; j < nums.size() ; ){
            if(nums[j] == 0){
                int r = Product(nums , i , j-1); //-2
                maxp = max(maxp , max(r,0)); //0
                while(j < n && nums[j] == 0){ j++ ; }
                i = j;
            }
            else{
                j++;
            }
        }
        if(i < n && i <= j){
        int r = Product(nums, i , j-1);
        maxp = max(maxp, r);
        }
        return maxp;
    }
};