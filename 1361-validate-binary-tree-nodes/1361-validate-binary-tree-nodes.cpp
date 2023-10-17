class Solution {
public:
   bool find(int i , vector<bool>& vis , int n , vector<int>& lftCh , vector<int>& rtCh){
    
        if(i >= n) return true;
        
        if(vis[i] == true) return false;
        
        vis[i] = true;
       
        bool ans1 = true;
        
        if(lftCh[i] != -1 ){
          ans1 =  find(lftCh[i] , vis , n , lftCh , rtCh);
        }
        if(rtCh[i] != -1){
          ans1 = ans1 & find(rtCh[i] , vis , n , lftCh , rtCh);
        }
        
        return ans1;
    }

    // NOTE : THE TRAVERSAL WILL START FROM  THE ROOT NODE , AND THE KEYPOINT IS 
    // THE NODE WHICH HAS NO PARENT IS THE ROOT NODE..
    // SO FIRST FIND THE PARENT OF EACH NODE
    
    bool validateBinaryTreeNodes(int n, vector<int>& lftCh, vector<int>& rtCh) {
        
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[i] = -1;
        }
        
        for(int i = 0 ; i < n ; i++){
           
            int lf = lftCh[i] , rt = rtCh[i];
            
         if(lf != -1){
               if(mp[lf]==-1)
                    mp[lf] = i;
                else 
                    return false;
            }
            
          if(rt != -1){
               if(mp[rt] == -1 )
                   mp[rt] = i ;
                else
                    return false;
            }
        }
        
     
        int cnt = 0; int root = -1;
        for(auto x : mp){
            if(x.second == -1) {cnt++; root= x.first; }
        }
        
        if(cnt != 1) return false;

          vector<bool> vis(n,false);
     bool ans1 = find(root , vis , n  , lftCh  , rtCh);
        
    for(auto i  : vis){
        if(i == false) return false;
    }

     return ans1;
    }
};