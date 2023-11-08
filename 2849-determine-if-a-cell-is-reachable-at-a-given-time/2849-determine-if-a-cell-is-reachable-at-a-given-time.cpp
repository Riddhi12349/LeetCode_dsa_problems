class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
      
        if(sx==fx && sy==fy) return t != 1;
           
    int t1 = max(abs(fx-sx) , abs(fy-sy));
        if(t1 <= t) return true;
        return false;
    }
};