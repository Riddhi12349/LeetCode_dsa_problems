class Solution {
public:
    using p = pair<int,int>;
    
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        
        int  n = r1.size();

        int sum = accumulate(r2.begin(),r2.end(),0);
        
        priority_queue<p,vector<p>,greater<p>> pq;
        
        for(int i = 0 ; i < n ; i++){
            int t = r2[i]-r1[i];
            pq.push({t,i});
        }
        
        while(!pq.empty() && pq.size()>n-k){
            p t = pq.top(); pq.pop();
            int indx  = t.second;
            sum += r1[indx];
            sum -= r2[indx];
        }
        
        return sum;
    }
};