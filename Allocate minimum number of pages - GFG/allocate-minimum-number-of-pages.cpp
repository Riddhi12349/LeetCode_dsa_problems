//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isVaild(int A[], int N_books , int M_students , int mxbooks){
        
        int students_total = 1;
        int sum = 0;
        
        for(int i = 0 ; i < N_books ; i++){
            
            sum += A[i];
            if(sum > mxbooks){
                students_total += 1;
                sum = A[i];
            }
        }
        // ****** IMPORTANT ******
        if(students_total > M_students){
            return false;
        }
        else{
            return true;
        }
    } 
    // 4 , 1
    //Function to find minimum number of pages.
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if(M > N){
            return -1;
        }
        
        int sum = 0;
        for(int i = 0 ; i < N ; i++){
            sum +=  A[i];
        }
        
        int mx = 0;
        for(int i = 0 ; i < N ; i++){
            mx = max(mx , A[i]);
        }
        
        //**** Creating a search space of maximum books that can be read by a student ****
        
        int low = mx;
        int high = sum ;
        // 40-60-100
        int res = 0;
        
        while(low < high){
            
            int mid = (low + high)/2;
            
            if(isVaild(A , N , M , mid) == true){
                // res = mid;
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends