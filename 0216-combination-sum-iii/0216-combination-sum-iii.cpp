class Solution {
public:
   
    vector<vector<int>> ans;
    
    void find(int st,int sum, int& k, int& tar, vector<int>& v1){
     
     if(sum>tar) return;
     if(v1.size()==k){ 
       if(sum==tar){
         ans.push_back(v1);
       }
         return;}
     if(st>9 || v1.size()>k) return;
        
     for(int i = st ; i <= 9 ; i++){
         if(sum+i>tar) break;
         v1.push_back(i); 
         find(i+1,sum+i ,k,tar,v1);
         v1.pop_back();
     } 
      
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        
        vector<int> v1;
        find(1,0,k,n,v1);
        
      
        return ans;
    }
};