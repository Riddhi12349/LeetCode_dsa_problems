class Solution {
public:
    
   // int mat[10005][10005];
    map <pair<int,int> , int> mp;
    int M,N;
    
 /*   void init(int m, int n) {
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                mp[{i,j}]++;
            }
        }

    } */
    
    Solution(int m,int n){
        M=m;N=n;
      //  init(m,n);
    }
    
    vector<int> flip() {
        
        int r = rand()%M;
        int c = rand()%N;
        
        if(mp.count({r,c})==0){
            mp[{r,c}]++;
            return {r,c};
        }
        else{
            return flip();
        }
    }
    
    void reset() {
      //  mp.clear();
    //    init(M,N);
        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */