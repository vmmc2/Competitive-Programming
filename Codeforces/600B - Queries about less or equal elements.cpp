#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999

using namespace std;

typedef long long ll;

vector<ll> va;
vector<ll> vb;

int binary_search(int find){
    int index = 1;
    int start = 0;
    int end = (int)va.size() - 1;
    while(start <= end){
        int mid = (start+end)/2;
        if(va[mid] == find){
            index = mid;
            start = mid + 1;
        }else if(va[mid] < find){
            start = mid + 1;
        }else if(va[mid] > find){
            end = mid - 1;
            index = mid;
        }
    }
    return index;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    ll aux;
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> aux;
        va.pb(aux);
    }
    for(int i = 0; i < b; i++){
        cin >> aux;
        vb.pb(aux);
    }
    sort(va.begin(), va.end());
    for(int i = 0; i < b; i++){
        int index = binary_search(vb[i]);
        if(vb[i] >= va.back()){
            cout << (int)va.size() << " ";
            continue;
        }
        if(va[index] != vb[i]){
            cout << index << " ";
        }else{
            cout << index + 1 << " ";
        }
    }
    return 0;
}
