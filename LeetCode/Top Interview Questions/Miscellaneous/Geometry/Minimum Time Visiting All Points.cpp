#include <bits/stdc++.h>

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if((int)points.size() <= 1) return 0;
        
        int minTime = 0;
        for(int i = 0; i < (int)points.size() - 1; i++){
            if(points[i][0] - points[i][1] == points[i + 1][0] - points[i + 1][1]){ //pontos na mesma diagonal crescente
                cout << "1" << endl;
                minTime += abs(points[i][0] - points[i][1]);
            }
            else if(points[i][0] + points[i][1] == points[i + 1][0] + points[i + 1][1]){ //pontos na mesma diagonal decrescente
                cout << "2" << endl;
                minTime += abs(max(points[i][0], points[i][1]) - min(points[i + 1][0], points[i + 1][1]));
            }
            else if(points[i][1] == points[i + 1][1]){ //pontos na mesma linha
                cout << "3" << endl;
                minTime += abs(points[i][0] - points[i + 1][0]);
            }
            else if(points[i][0] == points[i + 1][0]){ //pontos na mesma coluna
                cout << "4" << endl;
                minTime += abs(points[i][1] - points[i + 1][1]);
            }
            else{
                cout << "5" << endl;
                if((points[i][0] + points[i][1] + points[i + 1][0] + points[i + 1][1]) % 2 == 0){ //mesma paridade
                      
                }else{
                    
                }
            }
            cout << "minTime: " << minTime << endl;
        }
        
        return minTime;
    }
};
