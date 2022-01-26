#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    string s;

    cin >> s;

    s[0] = ((int)s[0] >= 65 && (int)s[0] <= 90) ? s[0] : (char)((int)s[0] - 32);

    cout << s << endl;

    return 0;
}
