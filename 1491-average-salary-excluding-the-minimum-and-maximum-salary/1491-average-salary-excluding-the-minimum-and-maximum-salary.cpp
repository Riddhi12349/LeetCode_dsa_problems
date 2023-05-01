class Solution {
public:
    double average(vector<int>& salary) {
     
        sort(salary.begin() , salary.end());  
        int sum = 0;
        for(int i = 1 ; i < salary.size()-1 ; i++){
            sum += salary[i];
        }
        double p = salary.size()-2;
        double avg = (float)sum/p;
        return avg;
    }
};