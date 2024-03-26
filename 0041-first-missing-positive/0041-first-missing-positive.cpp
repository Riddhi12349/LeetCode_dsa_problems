class Solution {
public:
void print(vector<int>& a){
    for(auto x : a) cout << x <<" ";
    cout<<endl;
}
    int firstMissingPositive(vector<int>& nums) {
//         [3,4,-1,1]
// POS=    [1,2,3,4,5,6,7,8,9]
       int n = nums.size();
    //     //vector<int> v1(n+1 , 0);
    //     for(int i = 1 ; i <= n ; i++){
    //         nums.push_back(-1);
    //     }
    //   //  print(nums);
    //     for(auto x : nums){
    //         if(x <= 0 || x > n) continue;
    //         nums[x+n-1] = x;
    //     }

    //     for(int i = 0 ; i < n ; i++){
    //         if(nums[n+i] != i+1) return i+1;
    //     }  

    //     return  n+1;


       for(int i = 0 ; i < n ; i++){
         // int prev = nums[i];
          while(nums[i] != i+1 && nums[i] > 0 && nums[i] <= n && nums[nums[i]-1]!= nums[i]){
             swap(nums[i] , nums[nums[i]-1]);
              }
       }

       for(int i = 0 ; i < n ; i++){
        if(nums[i] != i+1) return i+1;
       }

       return n+1;
    }
};