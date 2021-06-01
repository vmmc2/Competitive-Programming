class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int answer = -1;
        int counter = -1;
        int numVertices = (int)edges.size() + 1;
        vector<int> degree(numVertices + 1, 0);
        
        for(int i = 0; i < (int)edges.size(); i++){
            degree[edges[i][0]]++;
            if(degree[edges[i][0]] == numVertices - 1){
                return edges[i][0];
            }
            degree[edges[i][1]]++;
            if(degree[edges[i][1]] == numVertices - 1){
                return edges[i][1];
            }
        }
        return -1;
    }
};
