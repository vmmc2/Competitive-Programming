#include <bits/stdc++.h>

using namespace std;

int main(){
    int operations;
    string comand;
    int add, money = 0;
    scanf("%d", &operations);
    while(operations--){
        cin >> comand;
        if(comand == "donate"){
            scanf("%d", &add);
            money += add;
        }
        else{
            printf("%d\n", money);
        }
    }
    return 0;
}
