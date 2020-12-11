class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> dict1; //registra se existe interesse mutuo
        map<string,int> dict2; //registra soma de index minimo...
        vector<string> answer;
        
        for(int i = 0 ; i < (int)list1.size(); i++){
            dict1[list1[i]]++;
            dict2[list1[i]] += i;
        }
        for(int i = 0 ; i < (int)list2.size(); i++){
            dict1[list2[i]]++;
            dict2[list2[i]] += i;
        }
        int ans = 1e8;
        //Tem que descobrir o minimo primeiro
        for(map<string,int>::iterator it = dict1.begin(); it != dict1.end(); it++){
            if(it->second == 2){
                ans = min(ans, dict2[it->first]);
            }
        }
        //Agora eu guardo as respostas no vector
        for(map<string,int>::iterator it = dict2.begin(); it != dict2.end(); it++){
            if(it->second == ans && dict1[it->first] == 2) answer.push_back(it->first);
        }
        return answer;
    }
};
