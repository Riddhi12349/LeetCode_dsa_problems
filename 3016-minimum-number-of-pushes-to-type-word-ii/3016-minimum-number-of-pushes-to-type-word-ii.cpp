class Solution {
public:
    int minimumPushes(string word) {
      
    /*    int f[26]={0} , p[26]={0} , cnt = 0 , tmp = 1;
        
        for(int  i=0 ; i < word.size() ; i++){
            
            int indx = word[i]-'a';
            if(f[indx] == 0){
                cnt++;
            }
            f[indx]++;
            if(cnt > 8){
                cnt = 1;
                tmp++;
            }
            p[indx] = tmp;
        }
        
        int ans = 0;
        
        for(int i=0 ; i < 26 ; i++){
           cout << i << " " << f[i] << " " << p[i] << endl;
           ans += f[i]*p[i];  
        }
        
        */
        
        unordered_map<char,int> mp;
        
        for(int i=0 ; i < word.size() ; i++){
            mp[word[i]]++;
        }
        
        vector<int> fr;
        for(auto x : mp){
            fr.push_back(x.second);
        }
        
        sort(fr.begin() , fr.end() , greater<int>());
        
        int ans=0 , n = fr.size();
        
        int tmp=1;
  
        for(int i=0; i < n ; ){
           for(int j=1 ; j <= 8 && i < n ; j++ , i++){
                ans += fr[i]*tmp;
           }       
            tmp++;
        }
        return ans;
    }
};