#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    map <int,int> dictionary;
    int numcases;
    int numflakes;
    int id;
    int answer;
    int block;
    int cnt;
    scanf("%d", &numcases);
    for(int i = 1; i <= numcases; i++){
        scanf("%d", &numflakes);
        dictionary.clear();
        answer = 0, block = 0, cnt = 0;;
        for(int j = 1; j <= numflakes; j++){
            cin >> id;
            int aux = dictionary[id];
            if(aux != 0){
                block = max(block, aux);
                cnt = j-block-1;
            }
            cnt++;
            dictionary[id] = j;
            answer = max(answer,cnt);
        }
        cout << answer << endl;
    }
    return 0;
}
