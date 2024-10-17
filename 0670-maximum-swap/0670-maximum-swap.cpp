class Solution {
public:
    int maximumSwap(int num) {
        
     //  9,9,8,6,7,4,6,5 => 9,9,8,7,6,6,5,4
           
        string digits1 = to_string(num);
        string digits2 = digits1;
        
        sort(digits1.begin() , digits1.end() , greater<int>());
        
        for(int i = 0 ; i < digits1.size() ; i++){
            
            if(digits1[i] == digits2[i]) continue;
            
            //if not find position in digits2 , of digits1[i] , and then swap
            
            for(int j = digits2.size()-1 ; j >= i ; j--){
                if(digits2[j] == digits1[i]){
                    swap(digits2[j] , digits2[i]);
                    int ans = stoi(digits2);
                    return ans;
                }
            }
            
            
        }
        
        return num;
    }
};