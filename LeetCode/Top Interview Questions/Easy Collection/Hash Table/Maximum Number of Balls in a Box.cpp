class Solution {
public:
    int getSumOfDigits(int x){
        int sum = 0;
        while(x != 0){
            sum += x % 10;
            x = x/10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        map<int,int> counter;
        int answer = 0;
        
        for(int i = lowLimit; i <= highLimit; i++){
            int sum = getSumOfDigits(i);
            counter[sum]++;
            answer = max(answer, counter[sum]);
        }
        
        return answer;
    }
};
