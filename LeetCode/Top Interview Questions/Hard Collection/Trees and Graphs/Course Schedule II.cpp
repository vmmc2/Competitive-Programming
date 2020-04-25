class Solution {
public:
    vector<vector<int>> adjlist;
    vector<bool> visited;
    
    void cycle_detect(int source, stack<int> &pilha, bool &hasCycle){
        visited[source] = true;
        pilha.push(source);
        for(int i = 0; i < (int)adjlist[source].size(); i++){
            int x = adjlist[source][i];
            if(visited[x] == true){ //detected a cycle in my directed graph
                hasCycle = true;
                return;
            }
            else if(visited[x] == false){
                cycle_detect(x, pilha, hasCycle);
                if(hasCycle == true) return;
            }
        }
        visited[pilha.top()] = false;
        pilha.pop();
        return;
    }
    void toposort(int source, vector<int> &answer){
        visited[source] = true;
        for(int i = 0; i < (int)adjlist[source].size(); i++){
            int x = adjlist[source][i];
            if(visited[x] == false){
                toposort(x, answer);
            }
        }
        answer.push_back(source);
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer;
        //treating the corner cases...
        if(numCourses == 0) return answer;
        //first of all we have to build our graph
        adjlist.resize(numCourses);
        visited.resize(numCourses, false);
        for(int i = 0; i < (int)prerequisites.size(); i++){
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            adjlist[from].push_back(to);
        }
        //Our graph was built, now we must check if there is a cycle.
        //If we have a cycle in our graph, then.. we cannot find any possible topological sort.
        stack<int> pilha;
        bool hasCycle = false;
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == false){
                cycle_detect(i, pilha, hasCycle);
            }
        }
        //Checking if we have found a cycle, because if we had, then we cannot find the toposort.
        if(hasCycle) return answer;
        //We didn't find a cycle. So, there is a toposort on the graph.
        visited.resize(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == false){
                toposort(i, answer);
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
