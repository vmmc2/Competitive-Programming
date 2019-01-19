#include <iostream>
#include <vector>
#include <cmath>
#include<iomanip>

using namespace std;

int main(){  
    vector<int> quirkNumbers;
    for (int n = 0; n <= 9999; ++n){
        quirkNumbers.push_back(n * n);
    }    
    int d;
    while (cin >> d){
        for (int i = 0; i < quirkNumbers.size(); ++i){
            if (quirkNumbers[i] >= (int)pow(10.0, d)){
                break;
            }    
            int U = quirkNumbers[i] / (int)pow(10.0, d / 2);
            int L = quirkNumbers[i] % (int)pow(10.0, d / 2);
            if ((U + L) * (U + L) == quirkNumbers[i]){
                cout << setw(d) << setfill('0') << quirkNumbers[i] << endl;
            }    
        }
    }
    return 0;
}
