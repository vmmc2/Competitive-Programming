#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int row[8];
int a, b;
int linecounter;

bool place(int r, int c){
    for(int prev = 0; prev < c; prev++){
        if(row[prev] == r || (abs(row[prev] - r) == abs(c - prev))){
            return false;
        }
    }
    return true;
}

void backtrack(int c){
    if(c == 8 && row[b] == a){
        printf("%2d      %d", ++linecounter, row[0] + 1);
        for (int j = 1; j < 8; j++){
            printf(" %d", row[j] + 1);
        }
        printf("\n");
    }
    for(int r = 0; r < 8; r++){
        if(place(r, c)){
            row[c] = r;
            backtrack(c + 1);
        }
    }
    
}

int main(){
    int numcasos;
    scanf("%d", &numcasos);
    while(numcasos--){
        scanf("%d %d", &a, &b);
        a--;
        b--;
        memset(row, 0, sizeof row);
        linecounter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if(numcasos){
            printf("\n");
        }
    }
    return 0;
}
