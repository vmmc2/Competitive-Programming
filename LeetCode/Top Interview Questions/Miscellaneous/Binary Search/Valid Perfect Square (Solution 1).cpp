class Solution {
public:
    bool isPerfectSquare(int num) {
        bool answer = false;
        for(int i = 1; i <= sqrt(num); i++){
            if(num % i == 0 && i == num/i){
                answer = true;
                break;
            }
        }
        return answer;
    }
};

//Time-Complexity: O(sqrt(num))
