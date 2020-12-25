class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> visited;
        int answer = -1;
        for(int i = 0; i < (int)A.size(); i++){
            if(visited.find(A[i]) == visited.end()){
                visited.insert(A[i]);
            }else{
                answer = A[i];
                break;
            }
        }
        return answer;
    }
};
