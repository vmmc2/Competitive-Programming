#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

class shelter_queue{
  private:
    queue<pair<string,int>> dogs;
    queue<pair<string,int>> cats;
    int precedence = 1;
  public:
    void enqueue(string type){
        if(type == "dog"){
            dogs.push({"dog",precedence});
            precedence++;
        }else if(type == "cat"){
            cats.push({"cat",precedence});
            precedence++;
        }
        return;
    }
    pair<string,int> dequeueAny(){
        pair<string,int> ret;
        if(dogs.empty() && cats.empty()){
            throw "The shelter is empty! Come back later.\n";
        }
        if(dogs.empty() && !cats.empty()){
            ret = cats.front();
            cats.pop();
            return ret;
        }else if(!dogs.empty() && cats.empty()){
            ret = dogs.front();
            dogs.pop();
            return ret;
        }else{
            if(dogs.front().second < cats.front().second){
                ret = dogs.front();
                dogs.pop();
            }else{
                ret = cats.front();
                cats.pop();
            }
        }
        return ret;
    }
    pair<string,int> dequeueDog(){
        pair<string,int> ret;
        if(dogs.empty()){
            throw "No more dogs left! Try a cat.\n"; 
        }
        ret = dogs.front();
        dogs.pop();
        return ret;
    }
    pair<string,int> dequeueCat(){
        pair<string,int> ret;
        if(cats.empty()){
            throw "No more cats left! Try a dog.\n";
        }
        ret = cats.front();
        cats.pop();
        return ret;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    shelter_queue fila;
    
    fila.enqueue("cat");
    fila.enqueue("dog");
    fila.enqueue("dog");
    
    pair<string,int> ret;
    ret = fila.dequeueDog();
    cout << ret.first << " " << ret.second << "\n";
    ret = fila.dequeueDog();
    cout << ret.first << " " << ret.second << "\n";
    ret = fila.dequeueAny();
    cout << ret.first << " " << ret.second << "\n";
    
    return 0;
}
