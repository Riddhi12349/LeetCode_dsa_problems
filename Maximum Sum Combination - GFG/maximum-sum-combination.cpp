//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 
 public:
 
  class triplet{
      public:
      int val;
      int i_indx;
      int j_indx;
  };
  
  struct cmp{
  bool operator()(triplet a , triplet b){
      return a.val < b.val;
  }
 };
    
    vector<int> maxCombinations(int N, int k, vector<int> &A, vector<int> &B) {
        // code here
        
        sort(A.begin() , A.end());
        sort(B.begin() , B.end());
        
        priority_queue<triplet , vector<triplet> , cmp > mx_pq;
        map<pair<int,int> , int> map1;
        
        int t = A.size()-1 ,  p = B.size()-1;
        map1[{t,p}] += 1;
       
        mx_pq.push({A[t]+B[p] , t , p});
        
        vector<int> ans;
        
        while(k > 0){
        
        triplet t = mx_pq.top();
        mx_pq.pop();
        
        ans.push_back(t.val);
        
        int i = t.i_indx , j = t.j_indx;
         
        if(i > 0 && map1[{i-1 , j}] == 0){
            mx_pq.push({A[i-1]+B[j] , i-1, j});
            map1[{i-1 , j}] += 1;
        }
        
        if(j > 0 && map1[{i,j-1}] == 0){
            mx_pq.push({A[i]+B[j-1] , i, j-1});
            map1[{i , j-1}] += 1;
        }
        
         k--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends