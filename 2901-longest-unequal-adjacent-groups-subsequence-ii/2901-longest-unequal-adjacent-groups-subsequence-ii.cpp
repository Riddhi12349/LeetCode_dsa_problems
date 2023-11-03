class Solution {
public:
    
    int hdist(int i,int j,vector<string>& words){
        
        int cnt = 0;
        for(int t= 0 ; t < words[i].size() ; t++){
            if(words[i][t] != words[j][t]) cnt++;
        }
        return cnt;
        
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        vector<pair<int,int>> v1(n); //{ Mxlen Cons Words ,indx}
        
        int mxlen = 0 , mx_i = 0;
        
        for(int i = 0 ; i < n ; i++){
            v1[i] = {1,-1};
            for(int j = i-1 ; j >= 0 ; j--){
                if((words[i].size() == words[j].size()) &&
                   (groups[i] != groups[j]) && 
                  (hdist(i,j,words) == 1)){
                    if(v1[i].first < v1[j].first+1){
                        v1[i].first = v1[j].first+1;
                        v1[i].second = j;
                    }
                    if(mxlen < v1[i].first){
                        mxlen = v1[i].first; mx_i = i;
                    }
                }
            }
        }
        
        
        vector<string> ans;
  
        int now = mx_i;
        while(now != -1){
            ans.push_back(words[now]);
            now = v1[now].second;
        }
        
       
        reverse(ans.begin() , ans.end());
        return ans;
    }
};