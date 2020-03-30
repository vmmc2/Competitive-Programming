#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

bool oneAway(string s1, string s2){
    //As string podem estar one-away uma da outra se o tamanho entre elas diferir
    //por no maximo 1 caracter.
    int maximo = max(s1.length(), s2.length());
    int minimo = min(s1.length(), s2.length());
    if(maximo - minimo > 1) return false;
    //Agora tem que checar se elas estao de fato One-Away uma da outra.
    if(maximo == minimo){ //caso do replace.
        int diff = 0;
        for(int i = 0; i < maximo; i++){
            if(s1[i] != s2[i]) diff++;
        }
        if(diff == 1) return true;
        else return false;
    }
    //caso do insert/remove
    if(s1.length() < s2.length()){
        int index1 = 0;
        int index2 = 0;
        while(s1[index1] == s2[index2] && index1 < s1.length() && index2 < s2.length()){
            index1++;
            index2++;
        }
        index2++;
        while(index1 < s1.length()){
            if(s1[index1] != s2[index2]) return false;
            index1++;
            index2++;
        }
        return true;
    }else if(s2.length() < s1.length()){
        int index1 = 0;
        int index2 = 0;
        while(s2[index2] == s1[index1] && index1 < s1.length() && index2 < s2.length()){
            index1++;
            index2++;
        }
        index1++;
        while(index2 < s2.length()){
            if(s2[index2] != s1[index1]) return false;
            index1++;
            index2++;
        }
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1 = "pale";
    string s2 = "bae";
    
    if(oneAway(s1,s2)){
        cout << "The strings are one-away from each other." << "\n";
    }else{
        cout << "The string aren't one-away from each other." << "\n";
    }
    
    return 0;
}
