class Solution {
public:
    int find(int pos , int n , unordered_map<int,int>& mp , vector<int>& ans){
        
        if(pos > n) {
          
            //for(auto x : ans) cout << x  << " ";
            cout << endl;
            
            return 1;
        }
        
        int cnt = 0;
        
        for(int  i = 1 ; i <= n ; i++){
            if(((pos % i == 0)|| (i % pos == 0) )&& (mp.count(i) == 0)){
               
                mp[i]++; 
             //   ans.push_back(i);
               
                cnt += find(pos+1, n , mp , ans);
                mp.erase(i);
                
             //   ans.pop_back();
            }
        }
        
        return cnt;
    }
    
    int countArrangement(int n) {
        
        vector<int> ans;
        
        unordered_map<int,int> mp;
        return find(1,n , mp , ans);
    }
};