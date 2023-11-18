class Solution {
public:
    //simply 2 pointer , need to divide array into 2 parts and make the possible combinations....
    // we will match smallest (n/2) elements with largest (n/2) elements...........
    void print(vector<int>& v){
        for(auto i : v) cout << i << " ";
        cout << endl;
    }
    
    int maxNumOfMarkedIndices(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        
       int n = nums.size(); int mid = (n+1)/2;  int j = mid; int ans=0;
        vector<int> vis(n,0);
        
        print(nums);
        
       for(int i = 0 ; i < n && j < n ; ){
           if(nums[j] >= 2*nums[i]){ vis[i]=1; vis[j]=1;  ans+=2; 
                                    cout<<nums[i]<<" "<<nums[j]<<endl;
                                    i++;    j++;}
           else{ j++;}
       }
        
        return ans;
    }
};