class Solution {
public:
    void dfs(int source, vector<vector<int>> &adjlist, vector<int> &visited){
        visited[source] = 1;
        for(int i = 0; i < (int)adjlist[source].size(); i++){
            int x = adjlist[source][i];
            if(visited[x] == 0){
                dfs(x, adjlist, visited);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& M) {
        //conner cases
        if((int)M.size() == 0) return 0;
        if((int)M[0].size() == 0) return 0;
        //treating the normal cases...
        int n = (int)M.size();
        vector<vector<int>> adjlist;
        vector<int> visited;
        adjlist.resize(n);
        visited.resize(n, 0);
        
        //building our graph...
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(M[i][j] == 1){
                    adjlist[i].push_back(j);
                }
            }
        }
        int num_components = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                num_components++;
                dfs(i, adjlist, visited);
            }
        }
        return num_components;
    }
};
