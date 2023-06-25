//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        
        vector<vector<int>> v1(row , vector<int>(col , 0));
        
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                v1[i][j] = M[i][j];
            }
        }
        
        
        map<vector<int> , int> map1;
        
        for(int i = 0 ; i < row ; i++){
            map1[v1[i]] = 1;
        }
        
        vector<vector<int>> ans;
        
        for(int i = 0 ; i < row ; i++){
            if(map1[v1[i]] > 0){
                ans.push_back(v1[i]);
                map1[v1[i]] -= 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends