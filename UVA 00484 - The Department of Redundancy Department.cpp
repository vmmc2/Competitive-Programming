#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    unordered_map<int,int> dictionary;
    vector <int> naordem;
    set<int> jafoi;
    int num;
    while(scanf("%d", &num) != EOF){
        dictionary[num]++;
        if(jafoi.find(num) == jafoi.end()){
            naordem.push_back(num);
            jafoi.insert(num);
        }
    }
    for(int i = 0; i < naordem.size(); i++){
        printf("%d %d\n", naordem[i], dictionary[naordem[i]]);
    }
    return 0;
}
