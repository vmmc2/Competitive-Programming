class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1, index2;
        vector<int> answer;
        int n = (int)numbers.size();
        bool found = false;
        for(int i = 0; i < n; i++){
            index1 = i;
            int low = i + 1;
            int high = n - 1;
            int p2 = target - numbers[i];
            while(low <= high){
                int mid = low + (high - low)/2;
                if(numbers[mid] == p2){
                    answer.push_back(index1 + 1);
                    index2 = mid;
                    answer.push_back(index2 + 1);
                    found = true;
                    break;
                }else if(numbers[mid] > p2){
                   high = mid - 1; 
                }else if(numbers[mid] < p2){
                    low = mid + 1;
                }
            }
            if(found == true) break;
        }
        return answer;
    }
};
