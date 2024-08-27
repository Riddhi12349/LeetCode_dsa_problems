/*
SINCE WE ARE GIVEN START-PNT AND END-POINT OF TRAVERSAL , 
AND WE NEED TO FIND THE SHORTEST DISTANCE TO REACH FROM START TO END
SO , WE WILL APPLY BFS ALGORITHM

ALWAYS REMEMBER, TO FIND THE SHORTEST DISTANCE TO REACH FROM SOURCE TO DESTINATION , APPLY BFS ALGO

THE CHANGE IS THAT HERE NODES ARE STRING VALUES
*/
class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
         unordered_map<string,int> mp_vis;
         for(int i = 0 ; i < wordList.size() ; i++){
             mp_vis[wordList[i]] = 0;
         }

         queue<pair<string,int>> q;
         string st = beginWord;

         q.push({st, 1});
         int steps = 1;

        while(!q.empty()){
            
            string start = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(start == endWord) return steps;
        for(int i = 0 ; i < start.size() ; i++){
             char original = start[i];
          for(char ch = 'a' ; ch <= 'z' ; ch++){
                 start[i] = ch;
         if(mp_vis.count(start) > 0 && mp_vis[start] == 0){ 
             mp_vis[start] = 1;
             q.push({start , steps + 1});
              }
         }
         start[i] = original;
              }

        }

        return 0;

    }
};