#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;

class dsu{
    private:
        vector<int> p;
        vector<int> size;
    public:
        dsu(int n){
            size.assign(n, 1);
            p.resize(n);
            for(int i = 0; i < n; i++){
                p[i] = i;
            }
        }
        int get(int a){
            while(a != p[a]){
                a = p[a];
                p[a] = p[p[a]];
            }
            return p[a];
        }
        void unite(int a, int b){
            int rootA = get(a);
            int rootB = get(b);
            if(rootA != rootB){
                if(size[rootA] <= size[rootB]){
                    p[rootA] = rootB;
                    size[rootB] += size[rootA];
                }else{
                    p[rootB] = rootA;
                    size[rootA] += size[rootB];
                }
            }
        }
        void reset(int n){
            size.assign(n, 1);
            for(int i = 0; i < n; i++){
                p[i] = i;
            }
        }
};

double dist(pair<double,double> p1, pair<double,double> p2){
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt((dx*dx) + (dy*dy));
}

bool check(double radius, dsu &uf, vector<pair<double,double>> &points){
    bool answer = true;
    int n = (int)points.size();
    for(int i = 0; i < (int)points.size() - 1; i++){
        for(int j = i + 1; j < (int)points.size(); j++){
            if(dist(points[i], points[j]) < 2*radius){
                uf.unite(i, j);
            }
        }
    }
    for(int i = 0; i < (int)points.size(); i++){
        if(abs(100.00 - points[i].second) < 2*radius){
            uf.unite(n, i);
        }
        if(abs(-100.00 - points[i].second) < 2*radius){
            uf.unite(n + 1, i);
        }
    }
    if(uf.get(n) == uf.get(n + 1)){
        answer = false;
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    vector<pair<double,double>> points;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        points.push_back({(double)a, (double)b});
    }
    dsu uf(n + 2);
    //p[n + 1] -> reta: y = -100
    //p[n] -> reta: y = 100
    double low = 0.00, high = 100.00;
    double answer = 0.00;
    while(abs(high - low) > 1e-4){
        double mid = (low + high)/2;
        if(check(mid, uf, points) == true){
            answer = mid;
            low = mid;
        }else{
            high = mid;
        }
        uf.reset(n + 2);
    }

    cout << setprecision(6) << answer << endl;
    
    return 0;
}
