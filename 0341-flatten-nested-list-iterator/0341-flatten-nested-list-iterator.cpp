/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
/*
NESTEDLIST = [[1,1,1,2],2,4,6,[2,4,6,[8,2,[4,6,[2,4] ,6]] ] , 8]
*/
class NestedIterator {
public:

     vector<int> ans; int cnt;

     vector<int> getIntegerFromList(
         vector<NestedInteger>& nestedList){

        vector<int> v2;
         for(int i=0 ; i < nestedList.size() ; i++){
             
              bool isInt = nestedList[i].isInteger();
              if(isInt == true){
                int val = nestedList[i].getInteger();
                v2.push_back(val);
              }
              else{

 vector<int> v = getIntegerFromList(nestedList[i].getList());
                  for(int i = 0 ; i < v.size() ; i++){
                      v2.push_back(v[i]);
                  }
              }
         }
         return v2;
     }
    NestedIterator(vector<NestedInteger> &nestedList) {
     
     cnt = 0;

     for(int i = 0 ; i < nestedList.size() ; i++){  
           
        bool isInt = nestedList[i].isInteger();
        if(isInt == true){
            int val = nestedList[i].getInteger();
             ans.push_back(val);
        }
        else{
        
         vector<NestedInteger> v1 = nestedList[i].getList();
         vector<int> v = getIntegerFromList(v1);
         for(int i = 0 ; i < v.size() ; i++){
             ans.push_back(v[i]);
         }
        }
     }

    }
    
    
    int next() {
      if(cnt >= ans.size()) return -1;
      int val = ans[cnt];
      cnt++;
      return val;
    }
    
    bool hasNext() {
        if(cnt < ans.size()) return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */