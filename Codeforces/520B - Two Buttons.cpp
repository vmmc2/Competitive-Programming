#include <bits/stdc++.h>
#include <sstream>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 100000000;
const int MOD = 1e9 + 7;
int answer = 0;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int mog = m;

    if(m <= n){
        cout << abs(n - m) << endl;
    }else{
        queue<int> fila;
        vector<bool> visited(1e6, false);
        vector<int> dist(1e6, -1);
        dist[n] = 0;
        visited[n] = true;
        fila.push(n);
        while(!fila.empty()){
            int curr = fila.front();
            fila.pop();
            if(curr * 2 <= m * 2 && visited[curr * 2] == false){
                fila.push(curr * 2);
                visited[curr * 2] = true;
                dist[curr * 2] = dist[curr] + 1;
                if(curr * 2 == m){
                    cout << dist[curr * 2] << endl;
                    return 0;
                }
            }
            if(curr - 1 > 0 && visited[curr - 1] == false){
                fila.push(curr - 1);
                visited[curr - 1] = true;
                dist[curr - 1] = dist[curr] + 1;
                if(curr - 1 == m){
                    cout << dist[curr - 1] << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
