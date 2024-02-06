class Solution {
public:
    unordered_map <int,int> mp;
    int ans=0;
    
    void find(vector<int>& a, int i , int k){
              //, vector<int>& v1){
        
        if(i >= a.size()) { 
      //    if(v1.size()>0) 
            ans++;
            return; }
      
  //    if(mp.count(a[i]-k) == 0){
        if(mp[(a[i]-k)]<=0){
        mp[a[i]]++;
     //   v1.push_back(a[i]);
        find(a , i+1 , k );
    //    v1.pop_back();
     //   if(--mp[a[i]]==0){mp.erase(a[i]);}
          mp[a[i]]--;
      }  
        find(a, i+1 , k );
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        ans = 0;
        sort(nums.begin(),nums.end());
      //  vector<int> v1;
        find(nums,0,k);
        return ans-1;
    }
};