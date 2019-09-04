#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999

using namespace std;

bool check(string a1, string a2){
    if((a1[0] == a2[0]) ||(a1[1] == a2[1])){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int index = 0;
    string card;
    string aux, aux1;
    string temp;
    while(getline(cin, aux)){
            if(aux == "#") break; //fim dos casos de teste
            else{
                getline(cin,aux1);
                stringstream ss(aux); //pegando a primeira linha de cada caso de teste e jogando na stringstream
                int preenchendo = 0;
                deque<stack<string>>pilhas;
                for(int i = 0; i < 52; i++){
                    pilhas.push_back(stack<string>());
                }
                while(ss >> temp){
                    pilhas[preenchendo].push(temp);
                    preenchendo++;
                }
                stringstream ss2(aux1);
                preenchendo = 26;
                while(ss2 >> temp){
                    pilhas[preenchendo].push(temp);
                    preenchendo++;
                }
                int can;//suponho que não posso mais fazer jogadas;
                while(true){
                    can = 0;
                    for(int i = 0; i < (int)pilhas.size(); i++){
                        if(i >= 3 && check(pilhas[i - 3].top(), pilhas[i].top())){
                            string m1 = pilhas[i].top();
                            pilhas[i - 3].push(m1);
                            pilhas[i].pop();
                            can = 1;
                            if(pilhas[i].empty()){
                                pilhas.erase(pilhas.begin() + i);
                            }
                            break;
                        }else if(i >= 1 && check(pilhas[i - 1].top(), pilhas[i].top())){
                            string m1 = pilhas[i].top();
                            pilhas[i - 1].push(m1);
                            pilhas[i].pop();
                            can = 1;
                            if(pilhas[i].empty()){
                                pilhas.erase(pilhas.begin() + i);
                            }
                            break;
                        }
                    }
                    if(can == 0){ //nao consegui fazer nenhum movimento...
                        break;
                    }
                }
                if((int)pilhas.size() == 1){
                    printf("1 pile remaining: 52\n");
                }else if((int)pilhas.size() > 1){
                    printf("%d piles remaining: ", (int)pilhas.size());
                    for(int i = 0; i < (int)pilhas.size(); i++){
                        if(i != (int)pilhas.size() - 1){
                            printf("%d ", (int)pilhas[i].size());
                        }else{
                            printf("%d\n", (int)pilhas[i].size());
                        }
                    }
                }

            }
        }
    return 0;
}
