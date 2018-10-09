#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int i, queries;
    int xdivision, ydivision;
    int x, y;
    scanf("%d", &queries);
    while(queries != 0){
        scanf("%d %d", &xdivision, &ydivision);
        for(i = 1; i <= queries; i++){
            scanf("%d %d", &x, &y);
            if(x == xdivision || y == ydivision){
                printf("divisa\n");
            }
            else if(x > xdivision && y > ydivision){
                printf("NE\n");
            }
            else if(x < xdivision && y > ydivision){
                printf("NO\n");
            }
            else if(x < xdivision && y < ydivision){
                printf("SO\n");
            }
            else if(x > xdivision && y < ydivision){
                printf("SE\n");
            }
        }
        scanf("%d", &queries);
    }
    return 0;
}