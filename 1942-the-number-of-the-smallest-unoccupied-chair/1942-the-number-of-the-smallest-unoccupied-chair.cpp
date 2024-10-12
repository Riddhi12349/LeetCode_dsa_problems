class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        vector<pair<int,int>> arr , dept;
        
        int n = times.size();
        
        for(int i = 0 ; i < n ; i++){
            arr.push_back({times[i][0], i});
            dept.push_back({times[i][1] , i});
        }
        
        sort(arr.begin() , arr.end());
        sort(dept.begin() , dept.end());
        
        priority_queue<int,vector<int>,greater<int>> unoccupiedChairs;
        for(int k=0 ; k<n; k++) unoccupiedChairs.push(k);
        
        unordered_map <int,int> occupiedChairs;
        
        int i = 0 , j = 0;
        while(i < n){
            
            if(j<n && arr[i].first < dept[j].first){
                //next chair
                int person = arr[i].second;
                occupiedChairs[person] = unoccupiedChairs.top();
                unoccupiedChairs.pop();
                
                if(person == targetFriend){
                    return occupiedChairs[person];
                }
                
                i++;
            }
            else{
                int person = dept[j].second;
                
                //chair on which he left
                int chair = occupiedChairs[person];
                unoccupiedChairs.push(chair);
                
                occupiedChairs.erase(person);
                j++;
            }
        }
        
        return -1;
    }
};