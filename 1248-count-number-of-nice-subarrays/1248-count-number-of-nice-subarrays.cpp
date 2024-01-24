class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
       
        int n = a.size(); 
        vector<int> pref(n+1,0);
       
        for(int i=1 ; i <= n ; i++){
            pref[i] = pref[i-1];
            if(a[i-1] % 2 != 0)
                pref[i] += 1;
        }
        
        int tmp = -1;
        for(int j=1 ; j<=n ; j++){
            if(pref[j]==k){
                tmp = j; break;
            }
        }
        if(tmp==-1) return 0;
        int i=0;
        vector<int> ans(n+2,0);
        
        for(int j = tmp ; j <= n ; j++){
            
            int t = 0 , f=0;
            
            while(i<j && pref[j]-pref[i]==k){
                t++; i++; f=1;
            }
            
            if(f==1) ans[j] = t;
            else ans[j] = ans[j-1];
        }
        
        int res = accumulate(ans.begin(),ans.end(),0);
        return res;
    }
};