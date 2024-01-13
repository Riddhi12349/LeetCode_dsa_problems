class DataStream {
public:
    //vector<int> v1;
    int val,K,cnt_b , cnt_a;
    
    DataStream(int value, int k) {
 
       val = value; 
       cnt_b=0; cnt_a=0; K=k;
    }
    
    bool consec(int num) {
    
        if(num == val) cnt_a++;
        else {cnt_b++; cnt_a=0;}
     if(cnt_a >= K) return true;
      return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */