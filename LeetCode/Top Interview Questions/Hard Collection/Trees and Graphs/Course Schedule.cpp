#include <vector>

class Solution {
public:
    bool visited[100000] = {false};
    vector<vector<int>> adjlist;
    
    void dfs(int source, bool &hasCycle, stack<int> &pilha){
        pilha.push(source);
        visited[source] = true; //so pode considerar ciclo
        for(int i = 0; i < (int)adjlist[source].size(); i++){
            int x = adjlist[source][i];
            if(visited[x] == true){ //we have found a cycle...
                hasCycle = true;
                return;
            }else{
                dfs(x, hasCycle, pilha);
                if(hasCycle == true) return;
            }
        }
        visited[pilha.top()] = false;
        pilha.pop();
        return;
    } 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        //treating the corner cases...
        if(n == 0 || (int)prerequisites.size() == 0) return true;
        
        //solving for the general case..
        //first thing to do is to build our graph and resize our vector of visited vertices..
        adjlist.resize(n);
        for(int i = 0; i < (int)prerequisites.size(); i++){
            int from = prerequisites[i][1];
            int to =  prerequisites[i][0];
            adjlist[from].push_back(to); //building an edge to run the DFS.
        }
        //now we have build our graph... we must run the DFS from each vertex...
        //we are also going to assume that we dont have a cycle in our DAG and we are going to try to find one
        bool hasCycle = false;
        stack<int> pilha;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                dfs(i, hasCycle, pilha);
            }
        }
        if(hasCycle) return false;
        return true;
    }
};
