class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.size();
        vector<int> pref_n(n+2,0) , pref_y(n+2,0);
        
        int penalty = INT_MAX; int mn_hr = n;
         
        for(int i = 0 ; i < n ; i++){
         
            pref_n[i+1] = pref_n[i];  
            pref_y[i+1] = pref_y[i];
          
            if(customers[i] == 'Y')  pref_y[i+1] += 1; 
            else pref_n[i+1] += 1; 
            
        }
        
        for(int i = 1 ; i <= n+1 ; i++){
            
         int p = (pref_y[n]-pref_y[i-1])+(pref_n[i-1]);
         if(p < penalty){ penalty = p; mn_hr = i; }
       
        }
        
        cout << penalty << endl;
        return mn_hr-1;
    }
};