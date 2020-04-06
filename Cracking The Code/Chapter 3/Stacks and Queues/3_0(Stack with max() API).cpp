#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

//This is an optimal solution in which we improve the space complexity in the best case scenario...

class max_stack{
  private:
    stack<int> s;
    stack<pair<int,int>> cache;
  public:
    void push(int x){
        if(s.empty()){
            s.push(x);
            cache.push({x, 1});
        }else{
            s.push(x);
            if(x > cache.top().first){
                cache.push({x, 1});
            }else if(x == cache.top().first){
                pair<int,int> aux = cache.top();
                cache.pop();
                aux.second += 1;
                cache.push(aux);
            }else{
                //se for menor eu n faco nada...
            }
        }
        return;
    }
    void pop(){
        int topop = s.top();
        if(topop != cache.top().first){
            s.pop();
        }else{
            pair<int,int> aux = cache.top();
            aux.second -= 1;
            if(aux.second == 0){
                cache.pop();
            }else{
                cache.pop();
                cache.push(aux);
            }
            s.pop();
        }
        return;
    }
    int top(){
        return s.top();
    }
    int size(){
        return s.size();
    }
    bool isEmpty(){
        return s.empty();
    }
    int max(){
        return cache.top().first;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    max_stack ms;
    ms.push(13);
    ms.push(43);
    ms.push(0);
    cout << ms.max() << "\n";
    ms.push(-6);
    ms.push(132);
    cout << ms.max() << "\n";
    ms.push(46);
    ms.push(51);
    cout << ms.max() << "\n";
    ms.pop();
    ms.pop();
    ms.pop();
    cout << ms.max() << "\n";
    
    return 0;
}
