class Solution {
public:
    int partitionString(string s) {
        int i = 0 , j = 0 , cnt = 0;
        unordered_map<char , int> fmap;
        while(j < s.size()){
            if(fmap.count(s[j]) == 0){
                fmap[s[j]]++;
                j++;
            }
            else{
                cnt++;
                fmap.clear();
                i = j;
            }
        }
        return cnt+1;
    }
};