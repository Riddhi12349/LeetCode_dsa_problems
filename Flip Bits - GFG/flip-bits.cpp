//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n){
      
      int ones = 0;
      for(int i = 0 ; i < n ; i++){
          if(a[i] == 1) {
              ones++; a[i] = -1;
          }
          else{
              a[i] = 1;
          }
      }
      
      // find region of max-sum using kadane algo
      int sum = 0 , mxsum = 0;
      for(int i = 0 ; i < n ; i++){
              sum += a[i];
              mxsum = max(mxsum , sum);
              if(sum < 0) sum = 0;
      }
       
       return ones + mxsum;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends