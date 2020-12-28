class Solution {
public:
    void dfs(int x, unordered_map<int,string> &dict2, string &answer, vector<bool> & visited, vector<vector<int>> &adjlist){
        visited[x] = true;
        if((int)adjlist[x].size() == 0){
            answer = dict2[x]; 
            return;
        }
        for(int i = 0; i < (int)adjlist[x].size(); i++){
            int u = adjlist[x][i];
            if(visited[u] == false){
                dfs(u, dict2, answer, visited, adjlist);
            }
        }
        return;
    }
    string destCity(vector<vector<string>>& paths) {
        string answer = "";
        vector<vector<int>> adjlist(500, vector<int>());
        unordered_map<string,int> dict;
        unordered_map<int,string> dict2;
        int used = 0;
        for(int i = 0; i < (int)paths.size(); i++){
            if(dict.find(paths[i][0]) == dict.end()){
                dict[paths[i][0]] = used;
                dict2[used] = paths[i][0];
                used++;
            }
            if(dict.find(paths[i][1]) == dict.end()){
                dict[paths[i][1]] = used;
                dict2[used] = paths[i][1];
                used++;
            }
            adjlist[dict[paths[i][0]]].push_back(dict[paths[i][1]]);
        }
        vector<bool> visited(used, false);
        for(int i = 0; i < (int)visited.size(); i++){
            if(visited[i] == false){
                dfs(i, dict2, answer, visited, adjlist);
            }
        }
        
        return answer;
    }
};
