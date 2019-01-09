#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcasos;
    int battlefields;
    int greenarmy;
    int bluearmy;
    int aux;
    multiset<int, greater<int> >:: iterator it;
    multiset<int, greater<int> >:: iterator it2;
    multiset<int, greater<int> > GA;
    multiset<int, greater<int> > BA;
    vector <pair<int,int>> BF;
    pair<int,int> auxiliar;
    int maxdecampos;
    int j;
    int danogreen, danoblue;
    bool flag_first = false;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        if(flag_first){
			cout<<endl;
		}
        scanf("%d %d %d", &battlefields, &greenarmy, &bluearmy);
        for(j = 1; j <= greenarmy; j++){
            scanf("%d", &aux);
            GA.insert(aux);
        }
        for(j = 1; j <= bluearmy; j++){
            scanf("%d", &aux);
            BA.insert(aux);
        }
        //Comecou o parangole
        while(true){
            if(BA.empty() || GA.empty()){
                break;
            }
            maxdecampos = min(battlefields, min((int)BA.size(), (int)GA.size()));
            j = 1;
            for(it = GA.begin(), it2 = BA.begin(); j <= maxdecampos; j++){
                auxiliar.first = *it;
                auxiliar.second = *it2;
                GA.erase(it++);
                BA.erase(it2++);
                BF.push_back(auxiliar);
            }
            for(j = 0; j < BF.size(); j++){
                danogreen = BF[j].first;
                danoblue = BF[j].second;
                BF[j].first -= danoblue;
                BF[j].second -= danogreen;
            }
            for(j = 0; j < BF.size(); j++){
                if(BF[j].first > 0){
                    GA.insert(BF[j].first);
                }
                if(BF[j].second > 0){
                    BA.insert(BF[j].second);
                }
            }
            BF.clear();
        }
        if(BA.empty() && GA.empty()){
            printf("green and blue died\n");
        }
        else if(!GA.empty() && BA.empty()){
            printf("green wins\n");
            for(it = GA.begin(); it != GA.end(); ++it){
                cout << *it << endl;
            }
        }
        else if(!BA.empty() && GA.empty()){
            printf("blue wins\n");
            for(it = BA.begin(); it != BA.end(); ++it){
                cout << *it << endl;
            }
        }
        flag_first = true;
        GA.clear();
        BA.clear();
    }
    return 0;
}
