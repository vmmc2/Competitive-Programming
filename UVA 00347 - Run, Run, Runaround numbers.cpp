#include<cstdio>
#include<cstring>
 
char in[100];
int N, sols[9999999];
 
bool check(int n) {
    int cur = n % 10;
    int d[10] = { 0 };
    while(n != 0) {
        if(d[cur] || cur == 0) return false;
        d[cur] = 1;
        n /= 10;
        cur = n % 10;
    }
    return true;
}
 
bool simul(int n) {
    if(!check(n)) return false;
    sprintf(in, "%d", n);
    int ind = 0, d[10] = {0};
    char cur = in[0] - 48;
    for(int i = 0; i < strlen(in); i++) {
        if((ind = ind + cur % strlen(in)) >= strlen(in))
            ind = ind - strlen(in);
        if(d[cur] == 1) return false;
        d[cur] = 1;
        cur = in[ind] - 48;
    }
    if(cur == in[0] - 48)
        return true;
    return false;
}
 
int main() {
    for(int i = 9876543; i > 9; i--) {
        if(simul(i))
            sols[i] = i;
        else sols[i] = sols[i + 1];
    }
    for(int T = 1;; T++) {
        scanf("%d", &N);
        if(N == 0) break;
        printf("Case %d: %d\n", T, sols[N]);
    }
}
