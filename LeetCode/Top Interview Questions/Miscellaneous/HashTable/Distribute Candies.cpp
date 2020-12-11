class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int answer = 0;
        int ndiv2 = (int)candyType.size()/2;
        unordered_map<int,int> dict;
        
        for(auto x : candyType){
            dict[x]++;
        }
        
        for(unordered_map<int,int>::iterator it = dict.begin(); it != dict.end(); it++){
            answer++;
            ndiv2--;
            if(ndiv2 == 0) break;
        }
        
        return answer;
    }
};
