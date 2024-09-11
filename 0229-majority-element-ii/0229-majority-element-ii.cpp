class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        
        int el1 = INT_MIN , cnt1 = 0;
        int el2 = INT_MIN , cnt2 = 0;
        
        for(int  i = 0 ; i < a.size() ; i++){
            
            if(cnt1 == 0 && a[i] != el2){ //checking uniqueness
                el1 = a[i]; 
                cnt1=1;
            }
            else if(cnt2 == 0 && a[i] != el1){
                el2 = a[i];
                cnt2=1;
            }
            else if(a[i] == el1){
                cnt1++;
            }
            else if(a[i] == el2){
                cnt2++;
            }
            else{
                cnt1--; cnt2--;
            }
        }
        
        //check
        cnt1 = 0 ; cnt2 = 0;
        
        for(int i = 0 ; i < a.size() ; i++){
            if(el1 == a[i]) cnt1++;
            if(el2 == a[i]) cnt2++;
        }
        
        int mini = (a.size())/3;
        
        vector<int> ans;
        if(cnt1 > mini) ans.push_back(el1);
        if(cnt2 > mini) ans.push_back(el2);
        
        sort(ans.begin() , ans.end());
        
        return ans;
    }
};