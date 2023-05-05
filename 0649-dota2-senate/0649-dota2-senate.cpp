class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qd , qr;
        int n = senate.size();
        for(int i = 0 ; i < n  ; i++){
            if(senate[i] == 'R'){ qr.push(i);}
            else{ qd.push(i); }
        }
        while(!qd.empty() && !qr.empty()){
            int fr = qr.front() , fd = qd.front();
            qd.pop(); qr.pop();
            (fr < fd) ? qr.push(n+fr) : qd.push(fd+n);
        }
        
        return (qd.size() > qr.size()) ? "Dire" : "Radiant";  
    }
};