class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        
        int n = a.size();
        vector<int> v1(n,0) ;
          
       int j_pos = 0 , j_neg = 1;
        
        for(int i = 0 ; i < n ; i++){
            if(a[i] > 0){
                v1[j_pos] = a[i]; j_pos += 2; }
      
            if(a[i] < 0){
                v1[j_neg] = a[i]; j_neg += 2;
            }
        }
        
        return v1;
    }
};