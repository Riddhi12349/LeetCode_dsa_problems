class Solution {
public:
    long long putMarbles(vector<int>& wts, int k) {
        
        int n = wts.size();
       
        vector<int> sum;
        for(int i = 1 ; i < n ; i++){
           sum.push_back(wts[i]+wts[i-1]);
        }
 
  priority_queue<int> max_pq;
  priority_queue<int,vector<int>,greater<int>> min_pq;
  
  for(int i = 0 ; i<sum.size() ; i++){
    max_pq.push(sum[i]);
    min_pq.push(sum[i]);
  }

  long long mx_ans = wts[0] + wts[n-1];
  long long mn_ans = wts[0] + wts[n-1];

  int cnt = 0;
  while(cnt != k-1){

   mx_ans += max_pq.top();
   max_pq.pop();
   mn_ans += min_pq.top();
   min_pq.pop();
   cnt++; 
  }

  return mx_ans - mn_ans;
    }
};
//      [4,8,6]


// [1 , 3 , 5 , 2 , 4 , 6 , 8 , 7, 9]
// [2 , 4,  6 , 3,  5,  7 , 9 , 8 , 10]