class Solution {
public:
    using ll = long long;
    pair<ll , ll> findPosAndEle(vector<int>& a){
        
        ll s = 0 , pos = 0;
        for(int i = 0 ; i < a.size() ; i++){
            if(a[i] == 0) pos++;
            s += a[i];
        }
        
        return {s,pos};
    }
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long sum1 = 0 , pos1  = 0 , sum2 = 0 , pos2 = 0;
        
        pair<ll,ll> p = findPosAndEle(nums1);
        sum1 = p.first ; pos1 = p.second;
        
        p = findPosAndEle(nums2);
        sum2 = p.first ; pos2 = p.second;
        
        cout << sum1 << " " << pos1 << " " << sum2 << " " << pos2 << endl;
        
        if(pos1 == 0 && pos2 != 0){
            ll rem = sum1-sum2;
            if( rem < pos2 ) return -1;
            if( rem >= pos2 ) return sum1;        
        }
        else if(pos2 == 0 && pos1 != 0){
            ll rem = sum2-sum1;
            if(rem < pos1) return -1;
            if(rem >= pos1) return sum2;
        }
        else if(pos1 == 0 && pos2 == 0){
            return sum1==sum2 ? sum1 : -1;
        }
        else {
            if(sum1 > sum2){
                int diff = sum1-sum2;
                sum1 += pos1;
                if(diff + pos1  < pos2) {
                    sum1 += (pos2-diff-pos1);
                }
                return sum1;
            }
            else if(sum2 > sum1) {
                int diff = sum2-sum1;
                sum2 += pos2;
                if(diff + pos2 < pos1){
                    sum2 += (pos1 - diff-pos2);
                }
                return sum2;
            }
            else if(sum1 == sum2){
                sum1 += max(pos1,pos2); return sum1;
            }
        }
        return -1;
    }
};