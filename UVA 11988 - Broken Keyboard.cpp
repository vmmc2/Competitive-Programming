#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    string text;
    list <char> keyboard;
    list <char>:: iterator inicio;
    while(cin >> text){
        keyboard.clear();
        inicio = keyboard.begin();
        for(int i = 0; i < text.length(); i++){
            if(text[i] == '['){
                inicio = keyboard.begin();
            }
            else if(text[i] == ']'){
                inicio = keyboard.end();
            }
            else if(text[i] != '[' && text[i] != ']'){
                keyboard.insert(inicio, text[i]);
            }
        }
        for(list <char>:: iterator it = keyboard.begin(); it != keyboard.end(); it++){
            printf("%c", *it);
        }
        printf("\n");
    }
    return 0;
}
