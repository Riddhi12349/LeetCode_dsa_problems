class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
                    
        vector<int> Mins;
        
        for(int i = 0 ; i < timePoints.size() ; i++){
           
            int hrs = stoi(timePoints[i].substr(0,2));
            int mins = stoi(timePoints[i].substr(3));
            
            int time = hrs*60+mins;
            
            Mins.push_back(time);
        }
        
        sort(Mins.begin() , Mins.end());
        
        int d =  INT_MAX;
        
        int n = Mins.size();
        
        for(int i = 0 ; i < n-1 ; i++){

            d = min(d , Mins[i+1]-Mins[i]);
         
        }
        
         d = min(d,24*60 - (Mins[n-1]-Mins[0]));
        
        return d;

    }
};