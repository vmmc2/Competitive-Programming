#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

template <class T>
class queue_by_stacks{
  private:
    stack<T> enqst; //stack responsavel por suportar as operacoes de enqueue (insercao na fila).
    stack<T> deqst; //stack responsavel por suportar as operacoes de dequeue (remocao na fila).
  public:
    void enqueue(T element){
        enqst.push(element);
        return;
    }
    T dequeue(){
        T ret;
        if(!deqst.empty()){
            ret = deqst.top();
            deqst.pop();
            return ret;
        }else{
            while(!enqst.empty()){
                deqst.push(enqst.top());
                enqst.pop();
            }
            ret = deqst.top();
            deqst.pop();
            return ret;
        }
    }
    int size(){
        return (enqst.size() + deqst.size());
    }
    bool isEmpty(){
        if(enqst.size() == 0 && deqst.size() == 0) return true;
        else return false;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    queue_by_stacks<int> fila;
    fila.enqueue(1);
    fila.enqueue(10);
    fila.enqueue(3);
    fila.enqueue(2);
    cout << fila.dequeue() << "\n";
    cout << fila.dequeue() << "\n";
    fila.enqueue(5);
    fila.enqueue(4);
    cout << fila.dequeue() << "\n";
    cout << fila.dequeue() << "\n";
    cout << fila.dequeue() << "\n";
    
    return 0;
}
