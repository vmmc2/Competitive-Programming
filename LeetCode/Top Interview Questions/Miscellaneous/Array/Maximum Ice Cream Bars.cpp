class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i = 0;
        int answer = 0;
        while(i < (int)costs.size() && coins - costs[i] >= 0){
            coins -= costs[i];
            i++;
            answer++;
        }
        return answer;
    }
};
