#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    
    for(int a = 1; a <= numcasos; a++){
        set<string> alimentos;
        map<string,int> menores;
        map<string,int> maiores;
        map<string,pair<int,int>> media;
        
        int number_elements;
        cin >> number_elements;
        for(int b = 1; b <= number_elements; b++){
            string s;
            int price;
            cin >> s >> price;
            alimentos.insert(s);
            maiores[s] = max(maiores[s], price);
            if(menores[s] == 0){
                menores[s] = price;
            }else{
                menores[s] = min(menores[s], price);
            }
            media[s].first += price;
            media[s].second += 1;
        }
        cout << "Case #" << a << ":\n";
        for(set<string> :: iterator it = alimentos.begin(); it != alimentos.end(); it++){
            int medium = (media[*it].first/media[*it].second);
            cout << *it << " " << menores[*it] << " " << maiores[*it] << " " << medium << "\n"; 
        }
        cout << "\n";
    }
    
    return 0;
}
