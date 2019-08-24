#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 999999

using namespace std;

typedef long long ll;

int main(){
	int xdes, ydes, rxdes, rydes;
	int n;
	ll bestprice = 999999999999;
	while(scanf("%d %d %d %d", &xdes, &ydes, &rxdes, &rydes) == 4){
		scanf("%d", &n);
		ll bestprice = 999999999999;
		int x, y, rx, ry;
		ll price;
		for(int i = 0; i < n; i++){
			scanf("%d %d %d %d %lld", &x, &y, &rx, &ry, &price);
			int numh = 0, numv = 0;
			/*while(true){
				/*if(x >= xdes && y >= ydes && rx >= rxdes && ry >= rydes){

				}*/
			int numx, numx1, numy, numy1;
			if(xdes%x == 0){
				numx = xdes/x;
			}else if(xdes%x != 0){
				numx = xdes/x;
				numx++;
			}
			if(ydes%y == 0){
				numy = ydes/y;
			}else if(ydes%y != 0){
				numy = ydes/y;
				numy++;
			}
			if(rxdes%rx == 0){
				numx1 = rxdes/rx;
			}else if(rxdes%rx != 0){
				numx1 = rxdes/rx;
				numx1++;
			}
			if(rydes%ry == 0){
				numy1 = rydes/ry;
			}else if(rydes%ry != 0){
				numy1 = rydes/ry;
				numy1++;
			}
			/*int numy = ceil((double)ydes/y);
			int numx1 = ceil((double)rxdes/rx);
			int numy1 = ceil((double)rydes/ry);*/
			///printf("%d %d %d %d %lld\n", numx, numy, numx1, numy1, price);
			numx = max(numx, numx1);
			numy = max(numy, numy1);
			ll finalprice = (ll)(numx*numy)*price;
			bestprice = min(bestprice, finalprice);
		}
		printf("%lld\n", bestprice);
		
	}
	return 0;
}
