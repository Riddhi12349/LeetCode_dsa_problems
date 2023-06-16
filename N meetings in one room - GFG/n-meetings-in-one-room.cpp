//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    bool static compare(pair<int,int> p1 , pair<int,int> p2){
        return p1.second < p2.second;
    }
    
    int maxMeetings(int st[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v1;
        for(int i = 0 ; i < n ; i++){
            v1.push_back(make_pair(st[i] , end[i]));
        }
        
        sort(v1.begin() , v1.end() , compare);
        
        int ans = 1; int e = v1[0].second;
        for(int i = 1 ; i < n ; i++){
            if(v1[i].first > e) {
                ans++;
                e = v1[i].second;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends