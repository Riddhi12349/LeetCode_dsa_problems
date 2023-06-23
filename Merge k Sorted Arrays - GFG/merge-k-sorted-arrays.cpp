//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    
     class triplet{
       public:
       int val;
       int arr;
       int i_indx;
     };
     
     struct cmp{
      bool operator()(triplet a , triplet b){
         return (a.val > b.val);
     }
    };
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        priority_queue<triplet , vector<triplet> , cmp> pq_min;
        
      
        for(int i = 0 ; i < k ; i++){
            pq_min.push({arr[i][0] , i , 0});
        }
        
        vector<int> ans;
        
        while(ans.size() != k*k){
            
            triplet f = pq_min.top();
            pq_min.pop();
            
            ans.push_back(f.val);
            
            int arr_indx = f.arr , i = f.i_indx; 
            i = i+1;
            
            if(i < arr[arr_indx].size()){
               pq_min.push({arr[arr_indx][i] , arr_indx , i});
            } 
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends