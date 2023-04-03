class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
/*
     unordered_map<int , int> fmap;
     for(int i = 0 ; i < people.size() ; i++){
         fmap[people[i]]++;
     }
      int ans = 0;
      for(int i = 0 ; i < people.size() ; i++){
          if(fmap[people[i]] > 0){
              fmap[people[i]]--;
              int t = limit - people[i];
              if(fmap .count(t) > 0){
                  if(fmap[t] > 0){ fmap[t]--; }
              }
              else{
               //   t--;
                  while(t > 0){
                      if(fmap.count(t) > 0){
                         if(fmap[t] > 0){ fmap[t]--; break; }
                         }
                  t--; 
                 }
              }
            
              ans += 1;
          }
         
      }  
      */

    int ans = 0;
    sort(people.begin() , people.end());
    int i = 0 , j = people.size()-1;
    while(i <= j){
        if(people[i] + people[j] <= limit){
            i++;
            j--;
        }
        else{
            j--;
        }
        ans++;
    }
    return ans;


    }
};