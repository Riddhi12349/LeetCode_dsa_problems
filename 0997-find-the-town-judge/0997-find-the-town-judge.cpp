class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> mark(n+1 , 0) , vis(n+1 , 0);
        for(int i = 0 ; i < trust.size() ; i++){
            mark[trust[i][0]]=1;
            //for finding judge which donot trust anybody
            vis[trust[i][1]]+=1;
            //for finding judge which is trusted by everybody
        }
        
        
        for(int i = 1 ; i <= n ; i++){
            if(mark[i]==0 && vis[i]==n-1)
                return i;
        }
        
        return -1;
    }
};