class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        vector<pair<int,int>> arr; 
        vector<pair<int,int>> dept;
        
        int n = times.size();
        
        for(int i = 0 ; i < n ; i++){
            arr.push_back({times[i][0] , i});
            dept.push_back({times[i][1] , i});
        }
        
        sort(arr.begin() , arr.end());
        sort(dept.begin() , dept.end());
        
        unordered_map<int,int> occupied_Chairs;
        priority_queue <int,vector<int>,greater<int>> unoccupied_chairs;
        
        for(int k = 0 ; k < n ; k++){
            unoccupied_chairs.push(k);
        }
        
        int i = 0 , j = 0 , cnt= 0;
        
        while(i < n){
            
            if(j < n && arr[i].first < dept[j].first){
                cnt++;
                
                int person = arr[i].second;
                
                occupied_Chairs[person] = unoccupied_chairs.top();
                unoccupied_chairs.pop();
                
                if(person == targetFriend){
                    return occupied_Chairs[person];
                }
                i++;
            }
            else{
                int person = dept[j].second;
                
                unoccupied_chairs.push(occupied_Chairs[person]);
                occupied_Chairs.erase(person);
                j++;
            }     
            
        }
        
        return -1;
    }
};