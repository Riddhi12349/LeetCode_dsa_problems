class Solution {
public:
    int getCommon(vector<int>& a1, vector<int>& a2) {
        
     
        for(int i = 0 , j = 0 ; i < a1.size() && j < a2.size() ; ){
          
            if(a1[i] == a2[j]){ return a1[i];}
            else if(a1[i] > a2[j]){ j++; }
            else { i++; }
        }
          
        return -1;
    }
};