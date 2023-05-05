class Solution {
public:

    int maxVowels(string s, int k) {
      
      int maxi = 0 , cnt = 0 , i = 0 , j = 0;
      while(j < s.size()){
   if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
          cnt++;
   }
   if(j==(i+k-1)){
       maxi = max(maxi , cnt);
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
          cnt--;
   } 
   i += 1;
        }
    j++;
}
 
    return maxi;
    }
};