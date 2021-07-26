class Solution {
public:
    int secondHighest(string s) {
        map<int,int> freq;
        int answer = -1;
        for(int i = 0; i < (int)s.size(); i++){
            if((int)s[i] >= 48 && (int)s[i] <= 57){
                freq[(int)s[i] - 48]++;
            }
        }
        vector<int> v;
        for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
            v.push_back(it->first);
        }
        if((int)v.size() <= 1) return answer;
        sort(v.begin(), v.end());
        answer = v[(int)v.size() - 2];
        return answer;
    }
};
