#include <bits/stdc++.h>
#include <math.h>
#include <sstream>
#include <string.h>

using namespace std;

int main(){
    vector <pair<int,int>> pairs;
    int k;
    while(scanf("%d", &k) != EOF){
        pairs.clear();
        for(int i = k + 1; i <= 2*k; i++){
            if((i*k)%(i-k) == 0){
                pairs.push_back({(i*k)/(i-k),i});
            }
        }
        printf("%d\n", (int)pairs.size());
        for(int i = 0; i < (int)pairs.size(); i++){
            printf("1/%d = 1/%d + 1/%d\n", k, pairs[i].first, pairs[i].second);
        }
    }
    return 0;
}
