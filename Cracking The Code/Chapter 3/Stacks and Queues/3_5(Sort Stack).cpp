#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    stack<int> s1;
    stack<int> sorted;
    vector<int> answer;
    s1.push(34);
    s1.push(4);
    s1.push(-334);
    s1.push(600);
    s1.push(24);
    s1.push(98);

    //Iniciando o processo de sorting...
    while(!s1.empty()){
        if(sorted.empty()){
            sorted.push(s1.top());
            s1.pop();
        }else if(!sorted.empty()){
            if(s1.top() >= sorted.top()){
                sorted.push(s1.top());
                s1.pop();
            }else{ //s1.top() < sorted.top() -> ai tem que retirar ate achar a posicao correta.
                int ainserir = s1.top();
                s1.pop();
                int counter = 0;
                while(true){
                    if(sorted.empty()){
                        sorted.push(ainserir);
                        break;
                    }
                    if(ainserir < sorted.top()){
                        counter++;
                        s1.push(sorted.top());
                        sorted.pop();
                    }else{
                        sorted.push(ainserir);
                        break;
                    }
                }
                for(int i = 1; i <= counter; i++){
                    sorted.push(s1.top());
                    s1.pop();
                }
            }
        }
    }
    while(!sorted.empty()){
        answer.push_back(sorted.top());
        sorted.pop();
    }
    reverse(answer.begin(), answer.end());
    for(int i = 0; i < (int)answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
