class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer((int)boxes.size(), 0);
        for(int i = 0; i < (int)boxes.size(); i++){
            for(int j = 0; j < (int)boxes.size(); j++){
                if(i != j){
                    if(boxes[j] == '1'){
                        answer[i] = answer[i] + abs(j - i);
                    }
                }
            }
        }
        
        
        return answer;
    }
};
