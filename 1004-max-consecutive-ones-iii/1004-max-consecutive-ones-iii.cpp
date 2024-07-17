class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        
        int n = a.size()  , cnt = 0, ans = 0 , j = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            if(a[i] == 0) cnt++;
            
            while(cnt > k){
                if(a[j] == 0) cnt--;
                j++;
            }
            
            ans = max(ans , i-j+1);
        }
        
        return ans;
    }
};