class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
        unordered_map<int,int> map;
        for(int i = 0 ; i < arr.size() ; i++){
            map[arr[i]]++;
        }

        int i = 0 , j = 0;
        while(j < arr.size()){
    
            if(map[arr[j]] >= 2){ 
                arr[i] = arr[j];
                arr[i+1] = arr[j];
                i += 2;
            }
            else{
                arr[i] = arr[j];    
                i += 1;
            }
              j = j + map[arr[j]];
        }
        return i;
    }
};