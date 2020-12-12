class Solution {
public:
    int maxLen = -1;
    string answer = "";
    void dfs(int source, vector<vector<int>> &adjlist, map<int,string> &dict2, vector<bool> &visited){
        visited[source] = true;
        cout << dict2[source] << " ";
        if((int)adjlist[source].size() == 0){
            if(dict2[source].size() > maxLen){
                maxLen = dict2[source].size();
                answer = dict2[source];
            }else if(dict2[source].size() == maxLen){
                if(dict2[source] < answer) answer = dict2[source];
            }
            return;
        }
        for(int i = 0; i < (int)adjlist[source].size(); i++){
            int u = adjlist[source][i];
            if(visited[u] == false) dfs(u, adjlist, dict2, visited);
        }
        return;
    }
    string longestWord(vector<string>& words) {
        map<string,int> dict1;
        map<int,string> dict2;
        vector<bool> visited(1050, false);
        vector<vector<int>> adjlist(1050, vector<int>());
        vector<int> indexLengthOne;
        
        for(int i = 0; i < (int)words.size(); i++){
            dict1[words[i]] = i;
            dict2[i] = words[i];
            if((int)words[i].size() == 1) indexLengthOne.push_back(i);
        }
        for(int i = 0; i < (int)words.size()-  1; i++){
            for(int j = i + 1; j < (int)words.size(); j++){
                if(fabs(words[i].size() - words[j].size()) == 1){
                    string shorts;
                    string large;
                    if(words[i].size() < words[j].size()){
                        shorts = words[i];
                        large = words[j];
                    }else{
                        shorts = words[j];
                        large = words[i];
                    }
                    if(shorts == large.substr(0, (int)large.size() - 1)){
                        adjlist[dict1[shorts]].push_back(dict1[large]);   
                    }
                }
            }
        }
        for(auto x : indexLengthOne){
            if(visited[x] == false) dfs(x, adjlist, dict2, visited);
            cout << "\n";
        }
        
        return answer;
    }
};
