class Solution {
public:
   static int countBits(int x){
        int cnt = 0;
        while(x){
            cnt += (x & 1);
            x >>= 1;
        }
        return cnt;
    }
    static bool cmp(int a , int b){

        int cnt1 = countBits(a);
        int cnt2 = countBits(b);

        if(cnt1 == cnt2) return (a < b);
        return (cnt1 <  cnt2) ;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin() , arr.end() , cmp);
        return arr;
    }
};