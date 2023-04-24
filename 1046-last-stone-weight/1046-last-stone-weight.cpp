class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

      
      //[ 1]
      int n = stones.size();
       for(int i = n-1 ; i > 0 ; i--){
        sort(stones.begin() , stones.end());
         int x = stones[i];
         int y = stones[i-1];
         stones.pop_back();
         stones[i-1] = abs(x-y);
       } 

       return stones[0];
    }
};