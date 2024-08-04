class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        //task cycle has length of (n+1)
        
        unordered_map<int,int> mp; //{i , freq}
        
        for(char ch : tasks){
            mp[ch-'A']++; //map -> to store freq of each task
        }
        
        priority_queue<int> pq; //to get max-freq of each task at top
        
        for(auto x : mp){
            pq.push(x.second);
        }
        
        int ans = 0;
        
        while(!pq.empty()){
            
            vector<int> tmp;
            for(int i = 1 ; i <= n+1 ; i++){          
              if(!pq.empty()){
                int f1 = pq.top();
                pq.pop();
                f1--;               
                tmp.push_back(f1);      
               }       
            }
            
            for(int j = 0; j < tmp.size(); j++){
               if(tmp[j] > 0)
                pq.push(tmp[j]);
            }
            
            if(pq.empty()){
                ans += tmp.size();
            }
            else{
                ans += (n+1);
            }
            
        }
        
        return ans;
    }
};