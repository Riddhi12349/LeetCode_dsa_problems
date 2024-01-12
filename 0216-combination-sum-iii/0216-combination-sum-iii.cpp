class Solution {
public:
   
    map <vector<int>,int> mp;
    
    void find(int k, int n, vector<int> v1 , int st){
        
        if(v1.size()==k){
            
            if(n==0){
                /*
                cout<<"print\n";
                for(auto x : v1)
                    cout << x << " ";
                cout<< endl;
                */
                mp[v1]++; 
            }
            return;
        }
        
     for(int i = st ; i <= 9 ; i++){
      //   if(n-i<0) return;
         v1.push_back(i); //cout <<i<<" ";
         find(k,n-i,v1,i+1);
         v1.pop_back();
     } 
        cout<<endl;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        
        vector<int> v1;
        find(k,n,v1,1);
        
        for(auto x :mp)
            ans.push_back(x.first);
        
        return ans;
    }
};