class Solution {
public:
    string compare(string a , string b){
        if(a.size() < b.size())
            return a;
        else if(b.size() < a.size())
            return b;
        else if(b.size() == a.size()){
            if(a<b) return a;
            else return b;
        }
         return "";   
    }
    
    string merge2(string p , string q){
        
        if(p.size() == 0) return q;     ///aaa+abc
        
        for(int i = 0; i < p.size() ; i++){
          
            
            if(p[i] == q[0]){
                
                string tmp = p.substr(i);
                string tmp2 = q.substr(0 , min(tmp.size(),q.size()));
                
                if(tmp == tmp2){
             //       string t = p + q.substr(tmp.size());
                    string t = p + q.substr(tmp.size());
                    return t;
                }
                
            }
        }
        
        return p+q;
    }
    
    string merge(string i , string j , string k){
        
        if(i.find(j) != string::npos){
            if(i.find(k) != string::npos)
                return i;
            else
                return merge2(i,k);
        }
         else{
             string t = merge2(i,j);
             if(t.find(k) != string::npos)
                 return t;
             else
                 return merge2(t,k);
         }
        
        return i+j+k;
    }
   
    string minimumString(string a,
                         string b, string c) {
        
        string ans = "";
        
        int n = 3;
        vector<string> v1(n);
        v1[0] = a; v1[1] = b; v1[2] = c; 
        
        //aaa+abc
        
        vector<int> vis(n , 0);
        
        for(int i = 0 ; i < 3 ; i++){
           
            vis[i]=1;
        
            for(int j = 0 ; j < 3 ; j++){
                
                if(vis[j] == 0){
                    vis[j] = 1;
                for(int k = 0 ; k < 3 ; k++){
                    if(vis[k] == 0){
                      string tmp = merge(v1[i],v1[j],v1[k]);
                        cout << tmp << endl;
                        if(ans.size()==0)
                             ans = tmp;
                        else
                            ans = compare(ans,tmp);
                      
                    }
                }
                    vis[j] = 0;
                   }
                
            }
            
            vis[i] = 0;
            
        }
        
        return ans;
        
    }
};