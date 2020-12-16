class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //Da pra fazer com uma complexidade temporal melhor -> O(n)
        //Onde "n" é o tamanho do array "numbers"
        int n = (int)numbers.size();
        int low = 0;
        int high = n - 1;
        vector<int> answer;
        
        while(low <= high){
            if(numbers[low] + numbers[high] == target){
                answer.push_back(low + 1);
                answer.push_back(high + 1);
                break;
            }else if(numbers[low] + numbers[high] > target){
                high--;
            }else if(numbers[low] + numbers[high] < target){
                low++;
            }
        }
        
        return answer;
    }
};
