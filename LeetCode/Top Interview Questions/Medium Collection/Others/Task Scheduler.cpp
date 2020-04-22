#include <cmath>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hashtable(26, 0);
        for(int i = 0; i < (int)tasks.size(); i++){
            hashtable[tasks[i] - 'A']++;
        }
        sort(hashtable.begin(), hashtable.end());
        int max_val = hashtable[25] - 1;
        int idle_slots = max_val * n;
        for(int i =  24; i >= 0; i--){
            idle_slots -= min(max_val, hashtable[i]);
        }
        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
    }
};
