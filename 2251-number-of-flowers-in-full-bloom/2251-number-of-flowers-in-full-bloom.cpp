class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    
        vector<int> sorted_people_coming_time(people.begin() , people.end());
     
        sort(sorted_people_coming_time.begin() , sorted_people_coming_time.end());
        
        sort(flowers.begin() , flowers.end());
        
        priority_queue<int,vector<int>,greater<int> > pq;
        
        int i = 0; 
        
        unordered_map<int,int> mp;
        
        for(int t : sorted_people_coming_time){
            
            //push flowers ending time to a priority queue which have started blooming before coming of the person
            
            while(i < flowers.size() && flowers[i][0] <= t){
                pq.push(flowers[i][1]);
                i++;
            }
            
            while(!pq.empty() && pq.top() < t){
                pq.pop();
            }
            
            mp[t] = pq.size();
        }
        
        vector<int> ans;
        for(int p : people){
            ans.push_back(mp[p]);
        }
        
        return ans;
    }
};