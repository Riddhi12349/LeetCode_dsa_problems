class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        char prv = '#' , cur = '#';
        
        int n = sentence.size();
       
        if(sentence[0] != sentence[n-1]) return false;
        
        int i = 0;
        
        while(i < n){
        
            while(i+1 < n && sentence[i+1] != ' '){
                i++;
            }
            
            if(i+1 < n && sentence[i+1] == ' '){
                if(sentence[i] == sentence[i+2]){ i += 2; continue;}
                else{ return false; }               
            }
            
                i++;
        }
         
        return true;
    }
};