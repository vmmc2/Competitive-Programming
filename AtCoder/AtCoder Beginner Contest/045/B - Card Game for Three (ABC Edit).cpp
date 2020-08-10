#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string alice;
    string bob;
    string charlie;
    int cursora = 0;
    int cursorb = 0;
    int cursorc = 0;
    char turn = 'a';
    
    cin >> alice;
    cin >> bob;
    cin >> charlie;
    
    while(true){
        if(turn == 'a'){
            if(cursora >= (int)alice.size()){
                std::cout << "A" << "\n";
                return 0;
            }else{
                turn = alice[cursora];
                cursora++;
            }
        }else if(turn == 'b'){
            if(cursorb >= (int)bob.size()){
                std::cout << "B" << "\n";
                return 0;
            }else{
                turn = bob[cursorb];
                cursorb++;
            }
        }else if(turn == 'c'){
            if(cursorc >= (int)charlie.size()){
                std::cout << "C" << "\n";
                return 0;
            }else{
                turn = charlie[cursorc];
                cursorc++;
            }
        }
    }
    
    
    return 0;
}
