//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    priority_queue<int> mx_s;
    priority_queue<int,vector<int>,greater<int>> mn_g;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
       if( mx_s.size() == 0){
           mx_s.push(x);
           return;
       }
       
       if(mx_s.size() > mn_g.size()){
           if(x > mx_s.top()){
               mn_g.push(x);
           }
           else{
               mx_s.push(x);
               mn_g.push(mx_s.top());
               mx_s.pop();
           }
       }
       // size equal
       else{
          if(x < mx_s.top()){
              mx_s.push(x);
          } 
          else{
              mn_g.push(x);
              mx_s.push(mn_g.top());
              mn_g.pop();
          }
       }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(mx_s.size() == mn_g.size()){
            return (mx_s.top()+mn_g.top())/2.0;
        }
         return mx_s.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends