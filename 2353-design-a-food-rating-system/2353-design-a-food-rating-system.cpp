class FoodRatings {
public:
     
    struct cmp{
     bool operator()(const pair<int,string>& p1 , const pair<int,string>& p2) const {

         if(p1.first == p2.first) 
         return p1.second < p2.second;
         
         return p1.first > p2.first;
     }
    };
     unordered_map <string,int> mp_f;
     unordered_map <string,string> mp_fc;
     unordered_map <string,set<pair<int,string>,cmp> > mp_c;
    
     
    FoodRatings(vector<string>& foods, 
    vector<string>& cusines, vector<int>& ratings){
        
        int n = foods.size();
 // FIND H-R AND 2ND H-R OFGIVEN CUISINE

        for(int i = 0 ; i < n; i++){
            mp_f[foods[i]] = ratings[i];
            mp_fc[foods[i]] = cusines[i];
            
            // if(mp_c.count(cusines[i]) == 0)
            // { mp_c[cusines[i]] = foods[i];}
            // else{
            //     string f = mp_c[cusines[i]];
            //     int r = mp_f[f];
            //     if(r < ratings[i]) 
            //         mp_c[cusines[i]] = foods[i];
            //     if(r == ratings[i])
            //         mp_c[cusines[i]] = min(f , foods[i]);
            // }
            
            mp_c[cusines[i]].insert({ratings[i] , foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        
        int r = mp_f[food];
        mp_f[food] = newRating;

        string c = mp_fc[food];
       // string f = mp_c[c];
        

        // if(r < newRating)
        //     mp_c[c] = food;
        // if(r == newRating)
        //     mp_c[c] = min(f , food);

        mp_c[c].erase({r,food});
        mp_c[c].insert({newRating,food});

    }
    
    string highestRated(string cuisine) {
       
    //   vector<string> f = mp_c[cuisine];
      
    //    int hr = 0; string ans = "";

    //    for(int i = 0 ; i  < f.size() ; i++){
    //     int r = mp_f[f[i]]; 
    //     if(r > hr){ ans = f[i]; hr = r; }
    //     if(r == hr) {
    //        ans = min(ans , f[i]);
    //     }
    //    }
    //     return ans;
      
         return (*(mp_c[cuisine].begin())).second;

       }
    
};