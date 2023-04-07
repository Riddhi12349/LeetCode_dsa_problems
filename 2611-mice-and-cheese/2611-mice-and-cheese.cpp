class Solution {
public:
 int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        
        int n = reward1.size();
       /*
        for(int i = 0 ; i < n ; i++){
            reward1[i] = max(reward1[i] , reward2[i]);
        }
              
        sort(reward1.begin() , reward1.end());
        int j = n-1 , cnt = 0 , ans = 0;
         key = key * 2;
        while(j >= 0 && cnt != key){
           ans += reward1[j];
            j--;
           cnt++;
        }
   
        return ans;
        */

        vector<int> diff(n , 0); 
         int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
           int x = (reward1[i] - reward2[i]);
            diff[i] = x;
            sum += reward2[i];
        }

        sort(diff.begin() , diff.end() , greater<int>());
       
        // for(int i = 0 ; i < n ; i++){
        //     sum += reward2[i];
        // }

        int p = 0;
        while(k != 0){
            sum += diff[p];
            p++;
            k--;
        }

        return sum;
    }
};