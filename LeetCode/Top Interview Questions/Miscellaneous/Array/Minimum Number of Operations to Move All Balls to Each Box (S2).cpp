class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer((int)boxes.size(), 0);
        set<int> positions;
        for(int i = 0; i < boxes.size(); i++){
            if(boxes[i] == '1') positions.insert(i);
        }
        for(int i = 0; i < boxes.size(); i++){
            for(set<int>::iterator it = positions.begin(); it != positions.end(); it++){
                answer[i] += abs(i - (*it));
            }
        }
        
        return answer;
    }
};
