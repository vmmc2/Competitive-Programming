#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
int num = 0;
 
void compute(string &draemoon, int cursor, int currentPos, int expectedFinalPos, int sz){
    if(cursor >= sz){
        if(currentPos == expectedFinalPos) num++;
        return;
    }
    if(draemoon[cursor] == '+'){
        compute(draemoon, cursor + 1, currentPos + 1, expectedFinalPos, sz);
    }else if(draemoon[cursor] == '-'){
        compute(draemoon, cursor + 1, currentPos - 1, expectedFinalPos, sz);
    }else{
        compute(draemoon, cursor + 1, currentPos + 1, expectedFinalPos, sz);
        compute(draemoon, cursor + 1, currentPos - 1, expectedFinalPos, sz);
    }
    return;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int finalPos = 0;
    int myFinalPos = 0;
    bool needProb = false;
    int den = 0;
    string drazil, draemoon;
 
    cin >> drazil;
    cin >> draemoon;
 
    for(auto ch : drazil){
        if(ch == '+') finalPos++;
        else finalPos--;
    }
 
    for(auto ch : draemoon){
        if(ch == '+') myFinalPos++;
        else if(ch == '-') myFinalPos--;
        else{
            den++;
            myFinalPos = 0;
            needProb = true;
        }
    }
 
    if(needProb){
        den = pow(2, den);
        compute(draemoon, 0, 0, finalPos, (int)draemoon.size());
        cout << fixed << setprecision(12) << (double)(num)/(double)(den) << endl;
    }else{
        if(myFinalPos == finalPos) cout << fixed << setprecision(12) << 1.000000000 << endl;
        else cout << fixed << setprecision(12) << 0.000000000 << endl;
    }
 
    return 0;
}
