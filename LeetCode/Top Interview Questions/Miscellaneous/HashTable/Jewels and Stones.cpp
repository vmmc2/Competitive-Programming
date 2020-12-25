class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jwl;
        int answer = 0;
        for(int i = 0; i < (int)jewels.size(); i++){
            jwl.insert(jewels[i]);    
        }
        for(int i = 0; i < (int)stones.size(); i++){
            if(jwl.find(stones[i]) != jwl.end()) answer++;
        }
        return answer;
    }
};
