class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        vector<vector<int>> ans;
        
        sort(a.begin() , a.end());
        
        int n = a.size();
        
        for(int i = 0 ; i < n ; i++){
            
            if(i-1 >= 0 && a[i] == a[i-1]) continue;
            
            int tar = 0-a[i];
            
            int  j = i+1 , k = n-1;
            
            while(j < k){
                
                int sum = a[j] + a[k];
                
                if(sum == tar){
                    ans.push_back({a[i] , a[j] , a[k]});
                    j++;
                    k--;
                }
                else if(sum > tar){
                    k--;
                }
                else{
                    j++;
                }
                
                while(j < k && j-1 > i && a[j]==a[j-1]){
                    j++;
                }
                while(k > j && k+1 < n && a[k]==a[k+1]){
                    k--;
                }
            }
        }
        
        return ans;

    }
};