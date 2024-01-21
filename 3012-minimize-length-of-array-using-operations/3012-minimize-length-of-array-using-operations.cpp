class Solution {
public:
    int minimumArrayLength(vector<int>& a) {
        
        sort(a.begin() , a.end());
        
        int n = a.size() , i=1 , cnt=1, m=0;
        
        for( ; i<n ; i++){
            if(a[i] == a[0]) 
                 cnt++;
            if(a[i] % a[0] != 0) return 1;
        }
        
        
   //     if(i-1>=0 && i < n) m = (a[i]%a[i-1]);
        if(cnt<3) 
            return 1;
        return (cnt+1)/2;
    }
};