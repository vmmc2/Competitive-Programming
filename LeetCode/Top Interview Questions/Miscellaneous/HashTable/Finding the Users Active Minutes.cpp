class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,set<int>> minutes_users;
        map<int,int> users_uam;
        vector<int> answer(k, 0);
        
        for(int i = 0; i < (int)logs.size(); i++){
            minutes_users[logs[i][1]].insert(logs[i][0]);
        }
        for(map<int,set<int>>::iterator it = minutes_users.begin(); it != minutes_users.end(); it++){
            set<int> current = it->second;
            for(auto x : current){
                users_uam[x]++;
            }
        }
        for(map<int,int>::iterator it = users_uam.begin(); it != users_uam.end(); it++){
            answer[it->second - 1]++;
        }
        
        return answer;
    }
};
