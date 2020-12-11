class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> dict;
        int answer = 0;
        for(auto x : nums){
            dict[x]++;
        }
        int i = 0;
        int fst;
        int qtd1;
        int snd;
        int qtd2;
        for(map<int,int>::iterator it = dict.begin(); it != dict.end(); it++){
            if(i == 0){
                fst = it->first;
                qtd1 = it->second;
            }else{
                snd = it->first;
                qtd2 = it->second;
                if(abs(fst - snd) == 1){
                    answer = max(answer, qtd1 + qtd2);
                }
                fst = snd;
                qtd1 = qtd2;
            }
            i++;
        }
        
        return answer;
    }
};
