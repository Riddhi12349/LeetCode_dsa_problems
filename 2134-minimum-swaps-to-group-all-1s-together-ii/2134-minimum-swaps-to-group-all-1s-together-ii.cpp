class Solution {
public:
    int minSwaps(vector<int>& a) {
        
        int cnt1 = 0 , n = a.size();
        
        for(int i = 0 ; i < n ; i++){
            if(a[i] == 1){
                cnt1++;
            }
            a.push_back(a[i]);
        }
        
        int i = 0 , j = 0 , sw = INT_MAX , cnt0 = 0;
        
        while(j < n*2){
            
            if(a[j] == 0) {
                cnt0++;
            }
            if(j-i+1 == cnt1){
                sw = min(sw , cnt0);
                if(a[i] == 0){
                    cnt0--;
                }
                i++;
            }
            j++;
        }
        
        return sw == INT_MAX ? 0 : sw;
        
    }
};