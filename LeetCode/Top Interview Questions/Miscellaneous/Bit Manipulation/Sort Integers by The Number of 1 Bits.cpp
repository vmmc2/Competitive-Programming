class Solution {
public:
    int getCount(int x){
        int count = 0;
        while(x != 0){
            if(x & 1 == 1) count++;
            x = x >> 1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> numbers; //first -> qty of 1 bits ----- second -> number itself
        for(int i = 0; i < (int)arr.size(); i++){
            numbers.push_back({getCount(arr[i]), arr[i]});
        }
        sort(numbers.begin(), numbers.end());
        for(int i = 0; i < (int)arr.size(); i++){
            arr[i] = numbers[i].second;
        }
        return arr;
    }
};
