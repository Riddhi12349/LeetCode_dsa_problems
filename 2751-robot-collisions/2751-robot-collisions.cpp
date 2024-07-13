class Solution {
public:
    using p = pair<int,int>;
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dir) {
        
        int n = pos.size() ; 
        priority_queue<p , vector<p> , greater<p>> mn_pq;

        for(int i = 0 ; i < n ; i++){
            mn_pq.push({pos[i] , i}) ; // { pos , indx }
        }
        
        stack<p> st;
    
        while(!mn_pq.empty()){

                p p1 = mn_pq.top(); mn_pq.pop();
                int i = p1.second;
             
              while(!st.empty()){
                    
                    int j = st.top().second;

               //     if((dir[i]=='R' && dir[j] == 'L')) // will not collide
                    if(dir[i]=='L' && dir[j]=='R'){
                       
                        if(health[i] > health[j]){
                            st.pop();
                            health[i] -= 1;
                            health[j] = -1;
                          //  st.push(p1);
                        }
                        else if(health[j] > health[i]){
                            health[j] -= 1;
                            health[i] = -1;
                            break;
                        }
                        else{
                            health[i] = -1; health[j] = -1;
                            st.pop();
                            break;
                        }
                    }
                    else {
                        st.push(p1); break;
                    }
                    
                }
                
               
                if(st.empty() && health[i] > 0) { st.push(p1); }
        }

       vector<int> ans;
         
       for(int i = 0 ; i < n ; i++){
           if(health[i] > 0) ans.push_back(health[i]);
       }

        return ans;
    }
};