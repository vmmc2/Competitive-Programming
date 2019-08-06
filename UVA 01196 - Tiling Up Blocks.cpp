#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 999999

using namespace std;

struct block{
    int l, m;
};

bool compare(block a, block b){
    if(a.l < b.l) return true;
    if(a.l == b.l && a.m < b.m) return true;
    else return false;
}

int main(){
    int numblocks;
    int n;
    while(scanf("%d", &numblocks) == 1 && numblocks != 0){
        int xesque, dele;
        vector<block> tiles;
        
        for(int i = 1; i <= numblocks; i++){
            scanf("%d %d", &xesque, &dele);
            tiles.pb({xesque,dele});
        }
        sort(tiles.begin(), tiles.end(), compare);
        int lis[numblocks];
        for(int i = 0; i < numblocks; i++){
            lis[i] = 1;
        }
        //show time do lis
        n = numblocks;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i - 1; j++){
                if(tiles[i].l >= tiles[j].l && tiles[i].m >= tiles[j].m){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        int answer = -999;
        //pegando a maior subsequencia...
        for(int i = 0; i < n; i++){
            answer = max(answer, lis[i]);
        }
        printf("%d\n", answer);
    }
    printf("*\n");
    return 0;
}
