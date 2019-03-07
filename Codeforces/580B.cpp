#include <bits/stdc++.h>

using namespace std;
long long cs[100001];
vector<pair<int,int>>v;
int main(){
    int n, d, i;
    scanf("%d %d", &n, &d);
    for(i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        cs[i] = v[i].second;
        if(i){
            cs[i] += cs[i-1];
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int auxiliar = lower_bound(v.begin(),v.end(),make_pair(v[i].first+d,-1))-v.begin()-1;
        long long now = cs[auxiliar];
        if(i){
            now -= cs[i-1];
        }  
        ans = max(ans,now);  
    }
    cout << ans;
    return 0;
}
