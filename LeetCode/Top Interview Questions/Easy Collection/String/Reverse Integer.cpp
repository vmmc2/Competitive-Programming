class Solution {
public:
   int reverse(int x) {
        int neg = 0;
        long long x1 = x;
        if(x1 < 0){
            neg = 1;
            x1 = x1*(-1);
        }
        vector<int> digits; //vetor que guarda os digitos presentes na ordem inversa...
        int aux;
        while(x1 != 0){
            //printf("oi rs\n");
            aux = x1 % 10;
            digits.push_back(aux);
            x1 = x1/10;
        }
        long long y = 0;
        int expi = 0;
        int tam = (int)digits.size();
        for(int i = tam - 1; i >= 0; i--){
            y += (long long)(digits[i]*pow(10, expi));
            expi++;
        }
        if(neg == 1){
            y = y*(-1);
        }
        //cout << y << "\n";
        long long LIM1 = (pow(2,31)) - 1;
        long long LIM2 = ((-1)*pow(2,31));
        //cout << y << " " << LIM1 << "\n";
        if(y > LIM1) return 0;
        if(y < LIM2) return 0;
        return (int) y;
        
}
};
