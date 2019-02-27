#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    char grid[100][100];
    int coordinateone[10000][2];
    int coordinatethree[10000][2];
    int M;
    int dist, minimum;
    int distancia;
    int flag1, flag3;
    while(scanf("%d\n", &M) == 1){
        for(int i = 0; i < M; i++){
            scanf("%s\n", grid[i]);
        }
        flag1 = 0;
        flag3 = 0;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < M; j++)
                if(grid[i][j]=='1'){
                    coordinateone[flag1][0] = i;
                    coordinateone[flag1][1] = j;
                    flag1++;
                }else if(grid[i][j]=='3'){
                    coordinateone[flag3][0] = i;
                    coordinateone[flag3][1] = j;
                    flag3++;
                }
            
        minimum = -1;
        //calculando a minima distancia para que a partir de qualquer celula com 1 seja possivel chegar a uma celula com 3 
        for(int i = 0; i < flag1; i++){
            dist = (1<<30);
            
            for(int j = 0; j < flag3; j++)
                dist = min(dist,abs(coordinateone[i][0]-coordinatethree[j][0])+abs(coordinateone[i][1]-coordinatethree[j][1]));
            
            minimum = max(minimum, dist);
        }
        
        printf("%d\n", minimum);
    }
    
    return 0;
}
