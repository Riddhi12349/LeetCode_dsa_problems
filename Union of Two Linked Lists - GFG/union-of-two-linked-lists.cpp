//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
}; 

*/
class Solution
{
    public:
    
    struct Node* makeUnion( Node* h1,  Node* h2)
    {
        // code here
        priority_queue<int , vector<int> , greater<int>> pq;
        unordered_map<int,int> mp;
        
        while(h1 != NULL){
        
        if(mp.count(h1->data) == 0){
         mp[h1->data] = 1;
         pq.push(h1->data);
         }
          h1 = h1->next;
        }
        
        while(h2 != NULL){
        
        if(mp.count(h2->data) == 0){
        mp[h2->data] = 1;
        pq.push(h2->data);
        }
         h2 = h2->next; 
        }
        
      Node* dummy = new Node(0);
        dummy->next = NULL;
       Node* temp = dummy;
        
        while(!pq.empty()){
        
        if(mp[pq.top()] > 0){
        temp->next = new Node(pq.top());
        mp[pq.top()] -= 1;
        pq.pop();
        temp = temp->next;
        }
        else{
        pq.pop();
        }
        }
        
        return dummy->next;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends