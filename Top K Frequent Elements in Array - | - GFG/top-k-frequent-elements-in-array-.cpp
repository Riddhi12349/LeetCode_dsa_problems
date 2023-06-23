//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > min_pq;
        unordered_map<int, int> map;
        
        for(int i = 0 ; i < nums.size() ; i++){
            map[nums[i]]++;
        }
        
        for(auto x : map){
            min_pq.push({x.second , x.first});
            if(min_pq.size() > k){ min_pq.pop(); }
        }
        
        vector<int> ans;
        while(k > 0){
            ans.push_back(min_pq.top().second);
            min_pq.pop();
            k--;
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends