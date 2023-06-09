class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int indx = 
 upper_bound(letters.begin(),letters.end(),target)-letters.begin();
    if(indx == -1 ||  indx == letters.size()) return  letters[0];
    return letters[indx];
    }
};