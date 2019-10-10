#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
double middle;
 
double dist(double meio, int index){
    double ind = (double)index;
    if(meio >= index){
        return (double)(meio - ind);
    }else{
        return (double)(ind - meio);
    }
}
 
struct comp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){//se a qtd de bolas no cesto for a msm...
            if(dist(middle, a.second) == dist(middle, b.second)){//se a distancia dos cestos for igual...
                return a.second > b.second; //olho pro indice.
            }else if(dist(middle, a.second) < dist(middle, b.second)){
                return false;
            }else{
                return true;
            }
        }
        else if(a.first < b.first){
            return false;
        }else if(a.first > b.first){
            return true;
        }
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    //m = number of balls;
    //n = number of baskets;
    middle = (double)(1 + n)/2;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
    register int x = 1;
    for(int i = 1; i <= n; i++){
        pq.push({0,i});
    }
    for(int i = 0; i < m; i++){
        pair<int,int> xesque = pq.top();
        pq.pop();
        cout << xesque.second << "\n";
        xesque.first += 1;
        pq.push(xesque);
    }
    return 0;
}
