class Solution {
public:
    using ll = long long;
    
    long long taskSchedulerII(vector<int>& tasks, int space) {
        
        unordered_map<ll,ll> mp;
        
        ll day = 1;
        
        for(int i = 0 ; i < tasks.size() ; i++){
      
            if(mp.count(tasks[i]) == 0){
                mp[tasks[i]] = day;        
            }
            else 
            {
                if(mp[tasks[i]]+space+1 <= day){
                     mp[tasks[i]] = day;
              //  day = mp[tasks[i]] + space + 1;
                 }
            else{
                ll t = mp[tasks[i]]+space+1;
                mp[tasks[i]] = t;
                day = t;
                }
        }
           cout<<day<<endl; 
            day++;
        }
            
        return day-1;
    }
};