//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void helper(vector<vector<int>> &m, int n ,int i , int j , vector<string>& ans , string s1) {
        
        if(i >= n ||  i < 0 || j >= n || j < 0){
            return;
        }
        
        if(m[i][j] == 0){
            return ;
        }
        
        if(i == n-1 && j == n-1){
            ans.push_back(s1);
            return;
        }
        
        m[i][j] = 0;
        
        helper(m , n , i+1 , j , ans , s1 + 'D');
        helper(m , n , i , j+1 , ans , s1 + 'R');
        helper(m , n , i , j-1 , ans , s1 + 'L');
        helper(m , n , i-1 , j , ans , s1 + 'U');
        
        m[i][j] = 1;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
       
        vector<string> ans; 
        string s1;
        
        helper(m , n , 0 , 0 , ans , s1);
        
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends