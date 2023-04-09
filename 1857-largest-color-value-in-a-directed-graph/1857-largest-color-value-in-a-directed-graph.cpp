// class Solution {
// public:
 
//   int dfs(int& j , vector<vector<int>>& adj_matrix , vector<int>& visited , int& col_val , string colors){
      
//       int n = adj_matrix.size();
//     //  if(visited[j] == 1) { return -1;}
     
//       visited[j] = 1;
//      // int col_val;
//   //    for(int t = j ; t < n ; t++){
//        for(int col = 0 ; col < n ; col++){
//            if(adj_matrix[j][col] == 1){
//                  if(colors[j] == colors[col]){ col_val++; }
//              col_val =   dfs(col , adj_matrix , visited , col_val , colors);
//         //  return x;
//            }
//        }
      
//       return col_val;

//     }

//     int largestPathValue(string colors, vector<vector<int>>& edges) {
        
//         int n = colors.size();
//         vector<vector<int>> adj_matrix(n , vector<int>(n,0));
//         vector<int> visited(n , 0);
//         for(int i = 0 ; i < edges.size() ; i++){
//             adj_matrix[edges[i][0]][edges[i][1]] = 1;
//         }
//         // int x = dfs(adj_matrix , visited);
//         // if(x == -1){ return -1; }

//         int col_val = 1;
//         int p = 1;
//       for(int i = 0 ; i < n ; i++){
//           for(int j = 0 ; j < n ; j++){
//               if(i != j && adj_matrix[i][j] == 1 && visited[j] == 0){
//                   visited[i] = 1;
//                if(colors[i] == colors[j]){ col_val++; }
//                int x =  dfs(j , adj_matrix , visited , col_val , colors);
//                col_val = x;
//              }
//              else{ return -1;}
//           }
//           p = max(p, col_val);
//           col_val = 1;
//       }
   
//      return p;
//     }
// };
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<int>> count(n, vector<int>(26));
        queue<int> q;

        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int answer = 0, nodesSeen = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            answer = max(answer, ++count[node][colors[node] - 'a']);
            nodesSeen++;

            for (auto& neighbor : adj[node]) {
                for (int i = 0; i < 26; i++) {
                    // Try to update the frequency of colors for neighbor to include paths
                    // that use node->neighbor edge.
                    count[neighbor][i] = max(count[neighbor][i], count[node][i]);
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return nodesSeen < n ? -1 : answer;
    }
};