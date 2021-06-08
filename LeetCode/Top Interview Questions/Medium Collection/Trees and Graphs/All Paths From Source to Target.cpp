class Solution {
public:
    void dfs(int source, int dest, vector<vector<int>> &answer, vector<int> &path, vector<vector<int>> &graph){
        if(source == dest){
            path.push_back(dest);
            answer.push_back(path);
            path.pop_back();
            return;
        }
        
        path.push_back(source);
        for(int i = 0; i < (int)graph[source].size(); i++){
            int u = graph[source][i];
            dfs(u, dest, answer, path, graph);
        }
        path.pop_back();
        
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int source = 0, dest = (int)graph.size() - 1;
        vector<vector<int>> answer;
        vector<int> path;
        
        dfs(source, dest, answer, path, graph);
        
        return answer;
    }
};
