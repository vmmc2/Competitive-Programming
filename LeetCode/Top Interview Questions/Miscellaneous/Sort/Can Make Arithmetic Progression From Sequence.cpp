class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if((int)arr.size() == 1) return true;
        sort(arr.begin(), arr.end());
        int razao = arr[1] - arr[0];
        bool answer = true;
        for(int i = 0; i < (int)arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] != razao){
                answer = false;
                break;
            }
        }
        return answer;
    }
};
