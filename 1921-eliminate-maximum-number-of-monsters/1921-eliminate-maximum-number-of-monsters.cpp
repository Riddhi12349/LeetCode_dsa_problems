class Solution {
public:

    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

           vector<int> t;
           for(int i = 0; i < dist.size() ; i++){
               t.push_back(ceil((float)dist[i]*1.0/speed[i]));
           }

           sort(t.begin() , t.end()); 
           int time_pass = 1 , ans = 1;

           for(int i= 1 ; i < t.size() ; i++){
               int x =  t[i]-time_pass;
               if(x <= 0) break;
               ans++; time_pass++;               
           }

           return ans;
    }
};