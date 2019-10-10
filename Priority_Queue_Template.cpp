#include <bits/stdc++.h>
using namespace std;

int N, M;

int dist(int x){
    return abs(x-(N/2));
}

bool cmp(int a, int b){
    if(dist(a) == dist(b)) return a<b;
    else return dist(a) < dist(b);
}

bool cmp2(int a, int b){
    return !cmp(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    N = 10;
    
    priority_queue<int, vector<int>, decltype(&cmp2)> pq(cmp2);
    
    pq.push(2);
    pq.push(3);
    cout << pq.top() << '\n';
    
    pq.push(4);
    pq.push(5);
    cout << pq.top() << '\n';
    
    pq.push(6);
    pq.push(7);
    cout << pq.top() << '\n';

    for(int i=0; i<N; i++){
        cout << ord[i%M] << ' ';
    }

    return 0;
}
