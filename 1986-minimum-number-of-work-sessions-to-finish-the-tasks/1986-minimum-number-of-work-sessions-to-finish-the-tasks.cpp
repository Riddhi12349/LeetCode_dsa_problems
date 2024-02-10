class Solution {
public:
    bool find(int i,vector<int>& tasks , int sessTime , vector<int>& sess ,   int mid_sess){
       
        if(i>= tasks.size()) return true;
        
        for(int j=0 ; j<mid_sess ; j++){
            
            if(sess[j]+tasks[i] <= sessTime){
                sess[j] += tasks[i];
                if(find(i+1 , tasks, sessTime , sess , mid_sess))
                    return true;
                sess[j] -= tasks[i];
                if(sess[j]==0) return false;
            }
        }    
        return false;
    }
    
    int minSessions(vector<int>& tasks, int sessTime) {
        
        int n = tasks.size();
        int l = 1 , r = n;
        int ans = INT_MAX;
       
        while(l <= r){
            
            int mid = (l+r)/2;
            vector<int> sess(mid,0);
            
            if(find(0,tasks , sessTime , sess , mid)){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;            
        }
        
        return ans;
    }
};