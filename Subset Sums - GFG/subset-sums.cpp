//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    void helper(vector<int>& arr , int n , vector<int>& ans , int indx , int s){
        
        if(indx == n){
            ans.push_back(s);
            return ;
        }
        
//        ans.push_back(arr[indx]);
        s += arr[indx];
        helper(arr , n , ans , indx + 1 , s);
     //   ans.pop_back();
         s -= arr[indx];
        helper(arr , n , ans , indx+ 1 , s);
        
    
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        helper(arr , n , ans , 0 , 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends