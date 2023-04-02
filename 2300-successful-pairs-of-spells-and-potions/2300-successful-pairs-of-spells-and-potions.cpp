class Solution {
public:
  /*  int binarySearch(vector<int>& potions , int x){
          int l = 0 , h = potions.size()-1 , indx = -1;
          while(l <= h){
              int mid = (l + h)/2;
              if(potions[mid] == x){
                  return mid;
              }
              else if(potions[mid] > x){
                  indx = mid;
                  h = mid-1;
              }
              else {
                  l = mid+1;
              }
          }
          return indx;
    }*/
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
    
          vector<int> ans;
          int m = potions.size();
        sort(potions.begin() , potions.end());

        for(int i = 0 ; i < spells.size() ; i++){
        /*    long long t = (success  / spells[i]);
            int  p = (success % spells[i]);
            if(p != 0){
                t = t + 1;
            }
            int indx = binarySearch(potions , (int)t);
            if(indx != -1){  ans.push_back(0n-indx); }
            else{ ans.push_back(0); }
        }
*/
                          int low=0,high=m-1;
            
                        while(low<=high){
                             int mid=(low+high)/2;
                            long product = (long) spells[i] * potions[mid];
                            if(product>=success){
                                
                                high=mid-1;
                            }
                            else {
                                low=mid+1;
                            }

        }
      //number of elements having product > =  success will be the current element and the element to the right 
        ans.push_back(m-low);
        }
        return ans;
    }
};