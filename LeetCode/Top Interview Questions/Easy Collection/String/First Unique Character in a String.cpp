class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> dicio;
        //primeiro elemento do pair eh a qtd de ocorrencias.
        //segundo elemento do pair e a posicao da ultima ocorrencia daquele caractere na palavra
        for(int i = 0; i < (int)s.size(); i++){
            dicio[s[i]].first += 1;
            dicio[s[i]].second = i;
        }
        int answer = -1;
        int flagnachei = 0;
        for(unordered_map<char,pair<int,int>>::iterator it = dicio.begin(); it != dicio.end(); it++){
            if(it->second.first == 1){
                if(flagnachei == 0){
                    answer = it->second.second;
                    flagnachei = 1;
                }else{
                    if(it->second.second < answer){
                        answer = it->second.second;
                    }
                }
            }
        }
        return answer;
    }
};
