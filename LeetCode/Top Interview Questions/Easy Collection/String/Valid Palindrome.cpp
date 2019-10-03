class Solution {
public:
    bool isPalindrome(string s) {
        string frase = "";
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] >= 65 && s[i] <= 90){
                s[i] = (char)((int)s[i] + 32); //deixando tudo em lowercase...
            }
        }
        //montando uma nova string apenas com caracteres alfanumericos
        for(int i = 0; i < (int)s.size(); i++){
            if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)){
                frase += s[i];
            }
        }
        int tam = (int)frase.size();
        int fff = tam/2 - 1;
        int finale = tam - 1;
        bool ok = true;
        for(int i = 0; i <= fff; i++){
            if(frase[i] != frase[finale]) return false;
            finale--;
        }
        return true;
    }
};
