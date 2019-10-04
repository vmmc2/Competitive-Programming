class Solution {
public:
    int myAtoi(string str) {
        if(str == "") return 0;
        int neg = 0; //flag q me indica se o numero eh negativo ou nao
        vector<int> number;
        int i = 0;
        while(str[i] == ' '){
            i++;
        }
        //pronto aqui eu cheguei no meu parte do codigo em que a brincadeira comeca
        if((str[i] < 48 || str[i] > 57) && str[i] != '-' && str[i] != '+'){
            //cout << i << endl;
            //cout << "entrei" << "\n";
            return 0;
        }
        if(str[i] == '-'){
            neg = 1;
            i++;
        }else if(str[i] == '+'){
            i++;
        }
        while(str[i] >= 48 && str[i] <= 57 && i < (int)str.size()){
            number.push_back((int)str[i] - 48);
            i++;
        }
        unsigned long long x = 0;
        int exp = 0;
        int tam = (int)number.size();
        for(int i = tam - 1; i >= 0; i--){
            x += (number[i]*pow(10,exp));
            exp++;
        }
        if(neg == 1){
            x = x*(-1);
        }
        cout << x << "\n";
        if(x > pow(2,31) - 1) return (pow(2,31) - 1);
        if(x < (-1)*pow(2,31)) return ((-1)*pow(2,31));
        return (int) x;
    }
};
