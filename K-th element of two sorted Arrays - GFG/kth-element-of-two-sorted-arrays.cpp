//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
   
    
    int kthElement(int a1[], int a2[], int n, int m, int k)
    {
        
    //**** perform binary search on array of minimum size ****//
        if(n > m){
            return kthElement(a2 , a1,  m , n ,k);
        }

        int n1 = n , n2 = m;

// **** when k is greater than length of max array length --
 // -- then we have to pick minimum (k-m) = (7-5) = 2 -> elements from  arr1 ****//

        int low  = max( 0 , k - m);
        int high = min(k ,n);

        while(low <= high){

            int i1 = (low + high)/2;
            int i2 = k - i1;

            int lft_max1 = i1 == 0 ? INT_MIN : a1[i1-1];
            int lft_max2 = i2 == 0 ? INT_MIN : a2[i2-1];

            int rt_min1 = i1 == n1 ? INT_MAX : a1[i1];
            int rt_min2 = i2 == n2 ? INT_MAX : a2[i2];

            if(lft_max1 <= rt_min2 && lft_max2 <= rt_min1){
              
    //             if((n1 + n2)% 2 == 0){
    // double p = (max(lft_max1 , lft_max2) + min(rt_min1 , rt_min2))/2.0;
    //                 return p;
    //             }
    //             else{
                    return max(lft_max1 , lft_max2);
                // }
            }

            else if(lft_max1 > rt_min2){
                high = i1  - 1;
            }

            else{
                low = i1 + 1;
            }
        }
        return 0.0;
    }

};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends