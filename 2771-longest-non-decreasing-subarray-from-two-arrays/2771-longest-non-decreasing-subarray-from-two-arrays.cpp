class Solution {
public:
    int maxNonDecreasingLength(vector<int>& a1 , vector<int>& a2) {
        
        //RELATE THIS QS TO LONGEST - INCREASING - SUBSEQUENCE
        //Since it is SUBARRAY , so we need to see just our prevuious element
        int  n = a1.size();
        vector<int> len1(n , 1) , len2(n , 1);

        for(int i = 1 ; i < n ; i++){
            int len = 1;
            if(a1[i] >= a1[i-1])
             len = max(len , 1 + len1[i-1]);
            if(a1[i] >= a2[i-1])
             len = max(len , 1 + len2[i-1]);

             len1[i] = len; 
             len = 1;

            if(a2[i] >= a1[i-1])
              len = max(len , 1 + len1[i-1]);
            if(a2[i] >= a2[i-1])
              len = max(len , 1 + len2[i-1]);

              len2[i] = len;
            }

        int mxlen1 = *max_element(len1.begin() , len1.end());
        int mxlen2 = *max_element(len2.begin() , len2.end());

        return max(mxlen1 , mxlen2);
    }
};