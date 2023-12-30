class Solution {
public:
    bool isItPossible(string word1, string word2) {
    
    unordered_map <char,int> mp1  , mp2;
        
        /* *************** BRUTE FORCE ***************** */
        /*
        for(int i = 0 ; i < word1.size() ; i++){
            for(int j = 0 ; j < word2.size() ; j++){
                // swap w1[i] with w2[j] and check if both have same no of distinct chars.
                // if , then return true , else return back to same word's
          //**** Since , we have to make strings equal in exactly 1 move;
            
                
            }
        }
        */
       
   // 1. This has t.c. of O(N*N) which is large. So, we will reduce it to     O(26*26).
  
  // 2. Storing string chars in map--
      for(auto x : word1) mp1[x]++;
      for(auto x : word2) mp2[x]++;
   
  // 3. Iterating over all 26 alphabets and swapping b/c we have to make distincts equal in EXACTLY 1 MOVE....
      
        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < 26 ; j++){
                
                char ch1 = 'a' + i , ch2 = 'a' + j;
                
                if(mp1.count(ch1) && mp2.count(ch2)){
                    
                    // 4. SWAP___
                    
                    if(--mp1[ch1] == 0) mp1.erase(ch1);
                    if(--mp2[ch2] == 0) mp2.erase(ch2);
                    
                   
                    mp1[ch2]++;  mp2[ch1]++;
                    
                    if(mp1.size() == mp2.size()) 
                           return true;
                    
                    // 5. Back to Initial Pos(s), so SWAP, back____
                    
                    if(--mp1[ch2] == 0) mp1.erase(ch2);
                    if(--mp2[ch1] == 0) mp2.erase(ch1);
                    
                    mp1[ch1]++;  mp2[ch2]++;
                }
            }
        }
    
     return false;
    }
}; 