#include <bits/stdc++.h>

using namespace std;

bool hasUnique(string s1){
    int tam = (int)s1.length();
    for(int i = 0; i <= tam - 2; i++){
      if(s1[i] == s1[i + 1]) return false;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s = "abcde";
    sort(s.begin(), s.end());
    //A funcao sort() de C++ nao retorna a string ordernada(ou uma nova string ordernada). Ela faz tudo In-Place. Modificando a string original em si.
    if(hasUnique(s)){
      cout << "The string has all unique characters" << "\n";
    }else{
      cout << "The string has not unique characters" << "\n";
    }
    
    return 0;
}
