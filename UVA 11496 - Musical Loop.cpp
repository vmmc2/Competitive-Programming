#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    vector <int> music;
    int size, aux;
    int peaks;
    scanf("%d", &size);
    while(size != 0){
        peaks = 0;
        for(int i = 1; i <= size; i++){
            scanf("%d", &aux);
            music.push_back(aux);
        }
        if((music[0] > music[music.size()-1] && music[0] > music[1]) || (music[0] < music[music.size()-1] && music[0] < music[1])){
            peaks++;
        }
        for(int i = 1; i <= music.size()-2; i++){
            if((music[i] > music[i-1] && music[i] > music[i+1]) || (music[i] < music[i-1] && music[i] < music[i+1])){
                peaks++;
            }
        }
        if((music[music.size()-1] > music[music.size()-2] && music[music.size()-1] > music[0]) || (music[music.size()-1] < music[music.size()-2] && music[music.size()-1] < music[0])){
            peaks++;
        }
        printf("%d\n", peaks);
        music.clear();
        scanf("%d", &size);
    }
    return 0;
}
