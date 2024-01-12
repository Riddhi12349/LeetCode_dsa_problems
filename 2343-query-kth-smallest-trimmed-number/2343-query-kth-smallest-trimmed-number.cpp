class Solution {
public:
    vector<int> smallestTrimmedNumbers(
      vector<string>& a, vector<vector<int>>& q) {
       
        vector<int> ans;
        
      for(int i=0 ; i <q.size() ; i++){
          
          vector<pair<string,int>> v2;
          
        for(int j=0 ; j < a.size() ; j++){
            
            string t = a[j];
            int n=t.size();
            string p=t.substr(n-q[i][1]);
            v2.push_back({p,j});
        }
          
        sort(v2.begin(),v2.end());        
        ans.push_back(v2[q[i][0]-1].second);
          cout << v2[q[i][0]-1].first <<endl;
      }
        
        return ans;
    }
};