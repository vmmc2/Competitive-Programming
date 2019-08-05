#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

bool compare(tuple<int,int,int> a, tuple<int,int,int> b){
    int x1 = get<0>(a);
    int y1 = get<1>(a);
    int z1 = get<2>(a);
    int x2 = get<0>(b);
    int y2 = get<1>(b);
    int z2 = get<2>(b);
    if(x1 < x2) return true;
    if(x1 == x2 && y1 < y2) return true;
    if(x1 == x2 && y1 == y2 && z1 < z2) return true;
    else return false;
}

int main(){
    int numblocks;
    int x, y, z;
    tuple<int,int,int> aux;
    int caso = 1;
    int flag = 0;
    while(scanf("%d", &numblocks) == 1 &&  numblocks != 0){
        vector<tuple<int,int,int>> blocos;
        for(int i = 1; i <= numblocks; i++){
            scanf("%d %d %d", &x, &y, &z);
            blocos.pb(tuple<int,int,int>(x, y, z));
            blocos.pb(tuple<int,int,int>(y, x, z));
            blocos.pb(tuple<int,int,int>(x, z, y));
            blocos.pb(tuple<int,int,int>(z, x, y));
            blocos.pb(tuple<int,int,int>(y, z, x));
            blocos.pb(tuple<int,int,int>(z, y, x));
        }
        sort(blocos.begin(), blocos.end(), compare);
        int lis[6*numblocks];
        for(int i = 0; i <(int)blocos.size(); i++){
            lis[i] = 1;
        }
        lis[0] = get<2>(blocos[0]);
        for(int i = 1; i < 6*numblocks; i++){
            lis[i] = get<2>(blocos[i]);
            for(int j = 0; j <= i - 1; j++){
                int x1 = get<0>(blocos[i]);
                int y1 = get<1>(blocos[i]);
                int x2 = get<0>(blocos[j]);
                int y2 = get<1>(blocos[j]);
                if((x1 > x2 && y1 > y2) && lis[j] + get<2>(blocos[i]) > lis[i]){
                    lis[i] = lis[j] + get<2>(blocos[i]);
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < 6*numblocks; i++){
            answer = max(answer, lis[i]);
        }
        printf("Case %d: maximum height = %d\n", caso, answer);
        caso++;
    }
    return 0;
}
