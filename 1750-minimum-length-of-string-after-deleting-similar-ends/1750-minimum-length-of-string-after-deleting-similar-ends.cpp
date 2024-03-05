class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.size();
        int i = 0 , j = n-1;
        while(i < j){
            if(s[i]==s[j]){ 
                char ch = s[i];
                while(i<n && (s[i]==ch)){ i++; }
                while(j>i && (s[j]==ch)){ j--; }               
            }
            else{
                return (j-i+1);
            }
        }
        return (i+1!=j)?(j-i+1):0;
    }
};