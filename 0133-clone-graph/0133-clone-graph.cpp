/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
     unordered_map<Node* , Node*> map;
     // ek baar jo map bann gya bann gya
    Node* cloneGraph(Node* node) {
    
        if(node == NULL) {
            return NULL;
        }
        
       // unordered_map<Node* , Node*> map;
        if(map.find(node) == map.end()){
            map[node] = new Node(node->val , {});
            for(auto itr : node->neighbors){
                (map[node]->neighbors).push_back(cloneGraph(itr));
            }
        }

        return map[node];
    }
};











