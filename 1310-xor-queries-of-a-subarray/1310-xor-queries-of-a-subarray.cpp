class Solution {
public:
    int calc(int c , int a){
        
        vector<int> bits(32, 0);
        int i = 0;
        
        while(c > 0 || a > 0){
            
            int r1 = c % 2 , r2 = a % 2;
          
            c = c/2; 
            a = a/2;
            
            if(r1 == 0){
                bits[i] = r2;
            }
            else{
                bits[i] = !r2;
            }
            i++;
        }
        
        int b = 0;
        for(int i = 0 ; i < 32 ; i++){
            b = b + bits[i]*pow(2 , i);
        }
        
        return b;
    }
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        
        vector<int> prf(n,0);
        int a = 0;
        
        for(int i = 0 ; i < arr.size(); i++){
            a = a ^ arr[i];
            prf[i] = a;
        }
        
        vector<int> ans;
        
        for(int i = 0 ; i < queries.size() ; i++){
           
            int l = queries[i][0] , r = queries[i][1];
            
            int c = prf[r];
            int a = l-1 >= 0 ? prf[l-1] : 0;
            
            int b = calc(c , a);
            
            ans.push_back(b);            
        }
        
        return ans;
        
    }
};