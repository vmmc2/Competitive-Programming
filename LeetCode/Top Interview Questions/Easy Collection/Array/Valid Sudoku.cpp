class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true; //Assumo que a tabela de Sudoku ta correta.
        int vetor[10] = {0}; //vai funcionar como uma especie de hashtable. Acesso em O(1) sempre.
        //Checando cada linha.
        for(int i = 0; i < 9; i++){
            memset(vetor, 0, sizeof vetor); //zerando a hashtable a cada nova linha que verificamos.
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int x = (int)board[i][j] - 48;
                    vetor[x]++;
                    if(vetor[x] >= 2){
                        printf("entrei1");
                        valid = false;
                        goto dale;
                    }
                }
            }
        }
        //Checando cada coluna agr.
        for(int i = 0; i < 9; i++){
            memset(vetor, 0, sizeof vetor);
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    int x = (int)board[j][i] - 48;
                    vetor[x]++;
                    if(vetor[x] >= 2){
                        printf("entrei2");
                        valid = false;
                        goto dale;
                    }
                }
            }
        }
        //Checando agora cada um dos subquadrados 3x3 presentes na matrix 9x9
        memset(vetor, 0, sizeof vetor);
        int a, b;
        for(int i = 0; i <= 6; i = i + 3){
            for(int j = 0; j <= 6; j = j + 3){
                memset(vetor, 0, sizeof vetor);
                for(int k = i, a = 0; a <= 2; a++, k++){
                    for(int l = j, b = 0; b <= 2; b++, l++){
                        if(board[k][l] != '.'){
                            int x = (int)board[k][l] - 48;
                            vetor[x]++;
                            if(vetor[x] >= 2){
                                valid = false;
                                goto dale;
                            }
                        }
                    }
                }
            }
        }
        return valid;
        dale:
            return valid;
    }
};
