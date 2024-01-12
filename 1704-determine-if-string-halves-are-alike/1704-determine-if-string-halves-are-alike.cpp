class Solution {
public:
    int countVow(string t){
        
        int c1 = 0;
        for(int i = 0; i < t.size() ; i++){
            if(t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u'|| t[i]=='A'||t[i]=='E'||t[i]=='I'||t[i]=='O'||t[i]=='U')
                c1++;
        }
        
        return c1;
    }
    bool halvesAreAlike(string s) {
     
        int n = s.size();
        
        int i = n/2;
        
        string s1 = s.substr(0,i);
        string s2 = s.substr(i);
        
        int c1 = countVow(s1);
        int c2 = countVow(s2);
        
        return c1==c2 ? true : false;
    }
};