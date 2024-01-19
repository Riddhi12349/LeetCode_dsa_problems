class Solution {
public:
    bool checkOverlap(int r , int xc, int yc ,
                 int x1, int y1, int x2, int y2) {
        
        for(int i = x1 ; i <= x2 ; i++){
            for(int j = y1 ; j <= y2 ; j++){
                
                int d1 = i-xc , d2 = j-yc;
                if(d1*d1+d2*d2 <= r*r) return 1;
            }
     }
        return 0;
    }
};