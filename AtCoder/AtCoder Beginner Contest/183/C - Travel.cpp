#include <bits/stdc++.h>

using namespace std;

int answer = 0;

void backtrack(vector<vector<int>> &v, int expect, int numOfVisiteds, int n, int currentCity, int sumtime, vector<bool> &visited){
    numOfVisiteds++;
    visited[currentCity] = true;
    if(numOfVisiteds == n){
        sumtime += v[currentCity][0];
        //cout << "sumtime: " << sumtime << endl;
        if(sumtime == expect) answer++;
        visited[currentCity] = false;
        numOfVisiteds--;
        return;
    }
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            backtrack(v, expect, numOfVisiteds, n, i, sumtime + v[currentCity][i], visited);
        }
    }
    visited[currentCity] = false;
    numOfVisiteds--;
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, expect;
    cin >> n >> expect;

    vector<vector<int>> v(n, vector<int>());
    vector<bool> visited(n, false);
    int aux;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> aux;
            v[i].push_back(aux);
        }
    }
    int numberOfVisiteds = 0;
    int sumtime = 0;
    backtrack(v, expect, numberOfVisiteds, n, 0, sumtime, visited);

    cout << answer << endl;

    return 0;
}
