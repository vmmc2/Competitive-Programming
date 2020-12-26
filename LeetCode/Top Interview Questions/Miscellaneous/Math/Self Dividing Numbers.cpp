class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> answer;
        for(int i = left; i <= right; i++){
            if(i < 10){
                answer.push_back(i);
                continue;
            }
            if(i % 10 == 0) continue;
            bool selfDividing = true;
            string s = to_string(i);
            for(int j = 0; j < (int)s.size(); j++){
                if(s[j] == '0'){
                    selfDividing = false;
                    break;
                }
                if(i % (s[j] - '0') != 0){
                    selfDividing = false;
                    break;
                }
            }
            if(selfDividing == true) answer.push_back(i);
        }
        
        return answer;
    }
};
