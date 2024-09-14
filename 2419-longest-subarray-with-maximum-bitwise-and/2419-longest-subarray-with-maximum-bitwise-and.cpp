class Solution {
public:
    int longestSubarray(vector<int>& a) {
        
        int n = a.size();
        
        vector<int> andd(n , 0) , len(n,1); 
        andd[0] = a[0];
        
        int mxand = a[0];
        
        for(int i = 1 ; i < n ; i++){
            
            int t = a[i] & andd[i-1];
            if(t >= a[i]){
                andd[i] = t;             
            }
            else{
                andd[i] = a[i];
            }
            
            mxand = max(mxand , andd[i]);
            
            if(andd[i]==andd[i-1])
                len[i]=len[i-1]+1;
            else
                len[i]=1;
        }
        
        int mxlen = 0;
        
        for(int i = 0 ; i < n ; i++){
           if(andd[i] == mxand) mxlen = max(mxlen , len[i]);
        }
      
        return mxlen;
    }
};